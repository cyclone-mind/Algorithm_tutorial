#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>


template <typename T> class List {
  private:
    struct Node {
        T data;
        Node *next;
        Node *prev;
        // 易错点1: 默认构造函数应该用T()而不是0，保证类型安全
        Node() : data(T()), next(nullptr), prev(nullptr) {}
        // 易错点2: 参数名不能与成员变量同名，这里用nextNode避免命名冲突
        Node(const T &value, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };
    size_t size;
    Node *head;
    Node *tail;

  public:
    // 易错点3: 构造函数必须初始化所有成员变量为合理的初始值
    List() : size(0), head(nullptr), tail(nullptr) {}

    // 易错点4: 析构函数必须调用clear()释放所有动态内存
    ~List() { clear(); }

    void clear() {
        // 易错点5: 正确的链表清理方式，防止内存泄漏
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
        tail = nullptr; // 易错点6: 清理时必须同时重置tail指针
    }

    void push_back(const T &value) {
        // 易错点7: 新节点的next指向nullptr，prev指向当前tail
        Node *newNode = new Node(value, nullptr, tail);
        if (tail) {
            tail->next = newNode; // 易错点8: 更新原tail的next指针
        } else {
            head = newNode; // 易错点9: 空链表时，新节点既是head也是tail
        }
        tail = newNode; // 易错点10: 更新tail指针在size递增之前
        ++size;
    }

    void push_front(const T &value) {
        // 易错点11: 新节点的next指向当前head，prev指向nullptr
        Node *newNode = new Node(value, head, nullptr);
        if (head) {
            head->prev = newNode; // 易错点12: 更新原head的prev指针
        } else {
            tail = newNode; // 易错点13: 空链表时，新节点既是head也是tail
        }
        head = newNode;
        ++size;
    }

    size_t getSize() const { return size; }

    // 易错点14: 必须提供const和非const两个版本的[]运算符
    T &operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        Node *cur = head;
        // 易错点15: 边界检查必须在遍历之前进行
        while (index--) {
            cur = cur->next;
        }
        return cur->data;
    }

    const T &operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        Node *cur = head;
        while (index--) {
            cur = cur->next;
        }
        return cur->data;
    }

    void pop_back() {
        // 易错点16: 必须检查链表是否为空
        if (size > 0) {
            Node *newTail = tail->prev;
            delete tail;
            tail = newTail;
            if (tail) {
                tail->next = nullptr; // 易错点17: 更新新tail的next指针
            } else {
                head = nullptr; // 易错点18: 删除最后一个节点时，head也要置空
            }
            --size;
        }
    }

    void pop_front() {
        if (size > 0) {
            Node *newHead = head->next;
            delete head;
            head = newHead;
            if (head) {
                head->prev = nullptr; // 易错点19: 更新新head的prev指针
            } else {
                tail = nullptr; // 易错点20: 删除最后一个节点时，tail也要置空
            }
            --size;
        }
    }

    // 易错点21: 迭代器接口设计问题 - end()应该返回nullptr而不是tail
    Node *begin() { return head; }
    Node *end() { return nullptr; } // 修复：标准迭代器end()应该返回nullptr
    const Node *begin() const { return head; }
    const Node *end() const {
        return nullptr;
    } // 修复：标准迭代器end()应该返回nullptr

    void printElements() {
        // 易错点22: 遍历条件应该是cur != nullptr，这样更清晰
        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            std::cout << cur->data << " ";
        }
        std::cout << std::endl;
    }

    Node *getNode(const T &val) {
        Node *node = head;
        while (node != nullptr && node->data != val) {
            node = node->next;
        }
        return node;
    }

    // 易错点23: find函数返回类型错误，应该返回T*而不是解引用
    T *find(const T &val) {
        Node *node = getNode(val);
        if (node == nullptr) {
            return nullptr;
        }
        return &(node->data); // 修复：返回数据的地址，不是解引用
    }

    void remove(const T &val) {
        Node *node = head;
        while (node != nullptr && node->data != val) {
            node = node->next;
        }
        if (node == nullptr)
            return;

        // 易错点24: 删除节点时的指针更新逻辑复杂，需要仔细处理各种情况
        if (node != head && node != tail) {
            // 中间节点
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else if (node == head && node == tail) {
            // 易错点25: 这里是严重bug！应该用赋值=而不是比较==
            head = nullptr; // 修复：唯一节点
            tail = nullptr;
        } else if (node == head) {
            // 头节点
            head = node->next;
            if (head)
                head->prev = nullptr; // 易错点26: 需要检查head是否为空
        } else {
            // 尾节点
            tail = node->prev;
            if (tail)
                tail->next = nullptr; // 易错点27: 需要检查tail是否为空
        }
        --size;
        delete node;
    }

    bool empty() { return size == 0; }

    // 易错点28: 缺少拷贝构造函数和赋值运算符，可能导致浅拷贝问题
    // 建议添加：
    // List(const List& other);
    // List& operator=(const List& other);
};

// 易错点29: 友元函数或成员访问权限问题
template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &pt) {
    // 易错点30: 这里访问了私有成员head，需要声明为友元或提供公有接口
    for (typename List<T>::Node *cur = pt.head; cur; cur = cur->next) {
        os << " " << cur->data;
    }
    os << std::endl;
    return os;
}

int main() {
    List<int> myList;
    int n;
    std::cin >> n;
    std::cin.ignore(); // 易错点31: 正确处理输入缓冲区
    std::string line;

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        if (command == "push_back") {
            iss >> value;
            myList.push_back(value);
        } else if (command == "push_front") {
            iss >> value;
            myList.push_front(value);
        } else if (command == "pop_back") { // 易错点32: 命令字符串错误，多了()
            myList.pop_back();
        } else if (command == "pop_front") {
            myList.pop_front();
        } else if (command == "remove") {
            iss >> value;
            myList.remove(value);
        } else if (command == "clear") {
            myList.clear();
        } else if (command == "size") {
            std::cout << myList.getSize() << std::endl;
        } else if (command == "get") {
            iss >> value;
            // 易错点33: 应该添加边界检查，避免抛出异常
            try {
                std::cout << myList[value] << std::endl;
            } catch (const std::out_of_range &e) {
                std::cout << "Index out of range" << std::endl;
            }
        } else if (command == "print") {
            if (myList.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myList.printElements();
            }
        }
    }
    return 0;
}