#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename T> class Deque {
  private:
    T *elements;
    size_t size;
    size_t capacity;
    size_t frontIndex; // 易错点1: frontIndex指向队列第一个元素的位置
    size_t backIndex;  // 易错点2:
                      // backIndex指向队列最后一个元素的下一个位置（半开区间）

    void resize() {
        size_t newCapacity = capacity == 0 ? 1 : 2 * capacity;
        T *newElements = new T[newCapacity];
        size_t index = frontIndex;
        // 易错点3: 在循环队列中复制元素时，必须按照逻辑顺序重新排列
        for (size_t i = 0; i < size; i++) {
            newElements[i] = elements[index];
            index = (index + 1) % capacity; // 易错点4: 使用模运算处理环形索引
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
        // 易错点5: 扩容后重置索引，frontIndex从0开始，backIndex指向size位置
        frontIndex = 0;
        backIndex =
            size; // 修复：应该是size而不是0，因为backIndex指向末尾后一位
    }

  public:
    // 易错点6: 构造函数必须正确初始化所有成员变量
    Deque()
        : elements(nullptr), size(0), capacity(0), frontIndex(0), backIndex(0) {
    }

    // 易错点7: 析构函数必须释放动态分配的内存
    ~Deque() {
        clear();
        delete[] elements;
    }

    void push_front(const T &value) {
        // 易错点8: 插入前必须检查容量，满了就扩容
        if (size == capacity) {
            resize();
        }
        // 易错点9: 向前插入时，frontIndex需要向前移动，注意处理环形边界
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        elements[frontIndex] = value;
        ++size;
    }

    void push_back(const T &value) {
        if (size == capacity) {
            resize();
        }
        // 易错点10: backIndex设计为指向末尾元素后一个位置，便于插入操作
        elements[backIndex] = value;
        backIndex =
            (backIndex + 1) % capacity; // 易错点11: 插入后backIndex向后移动
        ++size;
    }

    void pop_front() {
        // 易错点12: 删除前必须检查队列是否为空
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        frontIndex = (frontIndex + 1) %
                     capacity; // 易错点13: 删除前端元素，frontIndex向后移动
        --size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        // 易错点14: 删除后端元素，backIndex需要向前移动，注意环形边界处理
        backIndex = (backIndex - 1 + capacity) % capacity;
        --size;
    }

    // 易错点15: 需要提供const和非const两个版本的[]运算符
    T &operator[](int index) {
        // 易错点16: 索引边界检查，注意使用int类型可能有负数
        if (index < 0 || index >= static_cast<int>(size)) {
            throw std::out_of_range("Index out of range");
        }
        // 易错点17:
        // 逻辑索引转换为实际数组索引，需要考虑frontIndex偏移和环形结构
        return elements[(frontIndex + index) % capacity];
    }

    // 易错点18: const版本的[]运算符返回类型应该是const T&
    const T &operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(size)) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }

    size_t getSize() const { return size; }

    void clear() {
        // 易错点19: 清空时只需要重置size，或者逐个删除元素
        while (size > 0) {
            pop_front();
        }
        // 更高效的方式：
        // size = 0;
        // frontIndex = 0;
        // backIndex = 0;
    }

    void printElements() {
        // 易错点20: 遍历时必须从frontIndex开始，按照逻辑顺序访问元素
        size_t index = frontIndex;
        for (size_t i = 0; i < size; i++) {
            std::cout << elements[index] << " ";
            index = (index + 1) % capacity; // 易错点21: 处理环形索引递增
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque<int> myDeque;
    size_t n;
    std::cin >> n;
    std::cin.ignore(); // 易错点22: 处理输入缓冲区的换行符

    std::string line;
    for (size_t i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        // 易错点23: 使用if-else链而不是独立的if语句，避免重复执行
        if (command == "push_back") {
            iss >> value;
            myDeque.push_back(value);
        } else if (command == "push_front") {
            iss >> value;
            myDeque.push_front(value);
        } else if (command == "pop_back") {
            // 易错点24: 删除操作前检查队列是否为空，避免异常
            if (myDeque.getSize() == 0) {
                continue; // 或者可以输出错误信息
            }
            myDeque.pop_back();
        } else if (command == "pop_front") {
            if (myDeque.getSize() == 0) {
                continue;
            }
            myDeque.pop_front();
        } else if (command == "clear") {
            myDeque.clear();
        } else if (command == "size") {
            std::cout << myDeque.getSize() << std::endl;
        } else if (command == "get") {
            iss >> value;
            // 易错点25: 访问元素时应该添加异常处理
            try {
                std::cout << myDeque[value] << std::endl;
            } catch (const std::out_of_range &e) {
                std::cout << "Index out of range" << std::endl;
            }
        } else if (command == "print") {
            if (myDeque.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myDeque.printElements();
            }
        }
    }
    return 0;
}
