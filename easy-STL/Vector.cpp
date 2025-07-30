#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>    // For std::copy, std::fill
#include <initializer_list> // For std::initializer_list

template <typename T> class MyVector {
  private:
    T *elements;
    size_t size;
    size_t capacity;

  private:
    void reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            T *newElements = new T[newCapacity];
            // 易错点1: 使用std::copy前需要确保elements不为空指针
            if (elements != nullptr) {
                std::copy(elements, elements + size, newElements);
            }
            delete[] elements; // 易错点2:
                               // 即使elements为nullptr，delete[]也是安全的
            elements = newElements;
            capacity = newCapacity;
            // 易错点3: newElements不需要置空，它是局部变量会自动销毁
        }
    }

  public:
    // 易错点4: 默认构造函数必须初始化所有指针为 nullptr
    MyVector() : elements(nullptr), size(0), capacity(0) {}

    // 支持列表初始化的构造函数
    // 例如: MyVector<int> v = {1, 2, 3};
    MyVector(std::initializer_list<T> initList)
        : elements(nullptr), size(0), capacity(0) {
        // 预分配足够的容量以避免多次重新分配
        reserve(initList.size());
        // 使用 std::copy 将初始化列表中的元素复制到内部数组
        std::copy(initList.begin(), initList.end(), elements);
        // 更新 size
        size = initList.size();
    }

    // 接受大小的构造函数，创建指定大小的向量
    // 例如: MyVector<int> v(10); // 创建大小为10的向量
    explicit MyVector(size_t count)
        : elements(nullptr), size(0), capacity(0) {
        // 预分配足够的容量
        reserve(count);
        // 初始化元素为 T() (默认构造)
        for (size_t i = 0; i < count; ++i) {
            new (elements + i) T(); // 使用 placement new 调用默认构造函数
        }
        // 更新 size
        size = count;
    }

    // 接受大小和默认值的构造函数
    // 例如: MyVector<int> v(10, 5); // 创建大小为10，所有元素为5的向量
    MyVector(size_t count, const T &value)
        : elements(nullptr), size(0), capacity(0) {
        // 预分配足够的容量
        reserve(count);
        // 使用 std::fill 初始化所有元素为指定值
        std::fill(elements, elements + count, value);
        // 更新 size
        size = count;
    }

    // 接受两个迭代器的构造函数，从其他容器范围初始化
    // 例如: std::vector<int> std_v = {1, 2, 3, 4, 5};
    //       MyVector<int> my_v(std_v.begin(), std_v.end());
    template <typename InputIt>
    MyVector(InputIt first, InputIt last)
        : elements(nullptr), size(0), capacity(0) {
        // 计算范围大小 (注意: 对于非随机访问迭代器, 这可能效率较低)
        size_t count = 0;
        for (InputIt it = first; it != last; ++it) {
            ++count;
        }
        // 预分配足够的容量
        reserve(count);
        // 使用 std::copy 复制元素
        std::copy(first, last, elements);
        // 更新 size
        size = count;
    }

    // 易错点5: 析构函数必须释放动态分配的内存
    ~MyVector() { delete[] elements; }

    // 易错点6: 拷贝构造函数使用初始化列表，避免重复初始化
    MyVector(const MyVector &other)
        : size(other.size), capacity(other.capacity) {
        // 易错点7: 如果capacity为0，不要分配内存
        if (capacity > 0) {
            elements = new T[capacity];
            std::copy(other.elements, other.elements + size, elements);
        } else {
            elements = nullptr;
        }
    }

    // 易错点8: 拷贝赋值运算符不能使用初始化列表，对象已存在
    MyVector &operator=(const MyVector &other) {
        // 易错点9: 自赋值检查是必须的，避免删除自己的内存
        if (this != &other) {
            delete[] elements; // 先释放旧内存
            capacity = other.capacity;
            size = other.size;
            if (capacity > 0) {
                elements = new T[capacity];
                std::copy(other.elements, other.elements + size, elements);
            } else {
                elements = nullptr;
            }
        }
        return *this; // 易错点10: 必须返回*this支持链式赋值
    }

    // 添加元素到末尾
    void push_back(const T &value) {
        // 易错点11: 扩容策略，初始容量为0时特殊处理
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : 2 * capacity);
        }
        elements[size++] = value; // 易错点12: 先赋值再递增size
    }

    // 获取元素个数
    size_t getSize() const { return size; }

    // 获取容量
    size_t getCapacity() const { return capacity; }

    // 访问指定索引处的元素（带边界检查）
    T get(size_t index) const {
        if (index >= size) {
            return -1; // 题目要求：索引无效返回-1
        }
        return elements[index];
    }

    // 易错点13: 提供const和非const两个版本的[]运算符
    T &operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T &operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    // 在指定位置插入元素
    void insert(size_t index, const T &value) {
        // 易错点14: index可以等于size（在末尾插入）
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : 2 * capacity);
        }
        // 易错点15: 从后往前移动元素，避免覆盖
        for (size_t i = size; i > index; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index] = value;
        size++;
    }

    // 删除数组末尾元素
    void pop_back() {
        // 易错点16: 检查容器是否为空
        if (size > 0)
            --size;
    }

    // 清空数组
    void clear() { size = 0; } // 易错点17: 只重置 size，不释放内存

    // 易错点18: 提供迭代器接口，const和非const版本
    T *begin() { return elements; }
    T *end() { return elements + size; }
    const T *begin() const { return elements; }
    const T *end() const { return elements + size; }

    // 遍历并打印数组元素（普通方式）
    void print() const {
        if (size == 0) {
            std::cout << "empty" << std::endl;
            return;
        }
        for (size_t i = 0; i < size; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    // 使用迭代器遍历并打印
    void printWithIterator() const {
        if (size == 0) {
            std::cout << "empty" << std::endl;
            return;
        }
        // 注意：这里直接调用begin()和end()，等同于this->begin()，不需要myVector.begin()
        // 因为在类内部，begin()等价于this->begin()，编译器会自动查找当前对象的成员函数
        for (const T *it = begin(); it != end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    // foreach遍历并打印
    void printWithForEach() const {
        if (size == 0) {
            std::cout << "empty" << std::endl;
            return;
        }
        for (size_t i = 0; i < size; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyVector<int> myVector;
    int n;
    std::cin >> n;

    // 易错点19: 混合使用cin>>和getline时，需要清除缓冲区的换行符
    std::cin.ignore(); // 或者用getchar()，但ignore()更标准

    std::string line;
    while (n--) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "push") {
            int value;
            // 易错点20: 从同一个字符串流读取参数，不要重新使用cin
            iss >> value;
            myVector.push_back(value);
        } else if (command == "size") {
            std::cout << myVector.getSize() << std::endl;
        } else if (command == "get") {
            int index;
            iss >> index;
            std::cout << myVector.get(index) << std::endl;
        } else if (command == "insert") {
            int index, value;
            iss >> index >> value;
            myVector.insert(index, value);
        } else if (command == "pop") {
            myVector.pop_back();
        } else if (command == "clear") {
            myVector.clear();
        } else if (command == "print") {
            myVector.print();
        } else if (command == "iterator") {
            myVector.printWithIterator();
        } else if (command == "foreach") {
            myVector.printWithForEach();
        }
        // 易错点21: switch语句不能直接用于string，要用if-else链
    }

    return 0;
}