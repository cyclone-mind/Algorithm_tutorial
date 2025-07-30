#include <algorithm>
#include <cstddef>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable {
    class HashNode {
      public:
        Key key;
        Value value;

        // 构造函数：只提供key时，value使用默认构造
        explicit HashNode(const Key &key) : key(key), value() {}
        // 构造函数：同时提供key和value
        HashNode(const Key &key, const Value &value) : key(key), value(value) {}

        // 重载运算符：用于HashNode之间的比较
        bool operator==(const HashNode &other) const {
            return key == other.key;
        }
        bool operator!=(const HashNode &other) const {
            return key != other.key;
        }

        // 易错点1：比较key的大小关系
        bool operator>(const HashNode &other) const { return key > other.key; }
        bool operator<(const HashNode &other) const { return key < other.key; }

        // 易错点2：用于HashNode与Key的比较
        bool operator==(const Key &key_) const { return key == key_; }

        void print() const { std::cout << key << " " << value << " "; }
    };

  private:
    using Bucket = std::list<HashNode>;
    std::vector<Bucket> buckets;
    Hash hashFunction;
    size_t tableSize;
    size_t numElements;
    float maxLoadFactor = 0.75; // 负载因子阈值，超过时需要rehash

    // 哈希函数：将key映射到桶的索引
    size_t hash(const Key &key) const { return hashFunction(key) % tableSize; }

    // 重新哈希：当负载因子过高时扩容
    void rehash(size_t newSize) {
        std::vector<Bucket> newBuckets(newSize);
        // 遍历所有旧桶，重新分配元素到新桶
        for (auto &bucket : buckets) {
            for (auto &hashNode : bucket) {
                size_t newIndex = hashFunction(hashNode.key) % newSize;
                newBuckets[newIndex].push_back(hashNode);
            }
        }
        buckets = std::move(newBuckets);
        tableSize = newSize;
    }

  public:
    // 构造函数：初始化哈希表
    HashTable(size_t size = 10, const Hash &hashFunc = Hash())
        : buckets(size), hashFunction(hashFunc), tableSize(size),
          numElements(0) {}

    // 插入操作
    void insert(const Key &key, const Value &value) {
        // 易错点3：检查负载因子，需要rehash时进行扩容
        if ((numElements + 1) > maxLoadFactor * tableSize) {
            if (tableSize == 0)
                tableSize = 1; // 防止除零错误
            rehash(tableSize * 2);
        }

        size_t index = hash(key);
        std::list<HashNode> &bucket = buckets[index];

        // 易错点4：std::find会调用operator==来比较HashNode和Key
        // 这里检查key是否已存在，如果不存在才插入（避免重复插入）
        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(HashNode(key, value));
            ++numElements;
        }
    }

    // 删除操作
    void erase(const Key &key) {
        size_t index = hash(key);
        auto &bucket = buckets[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
            numElements--;
        }
    }

    // 查找操作：返回指向value的指针，找不到返回nullptr
    Value *find(const Key &key) {
        size_t index = hash(key);
        auto &bucket = buckets[index];
        auto ans = std::find(bucket.begin(), bucket.end(), key);
        if (ans != bucket.end()) {
            return &ans->value;
        }
        return nullptr;
    }

    // 获取哈希表中元素个数
    size_t size() const { return numElements; }

    // 打印所有元素
    void print() const {
        for (size_t i = 0; i < buckets.size(); i++) {
            for (const HashNode &element : buckets[i]) {
                element.print();
            }
        }
        std::cout << std::endl;
    }

    // 清空哈希表，两种清空哈希表的方式。
    /*
    void clear() {
        // 易错点5：只清空每个桶的内容，保持桶的数量不变
        // 这样可以保证重新插入时元素的哈希位置一致，维持打印顺序
        for (auto &bucket : buckets) {
            bucket.clear();
        }
        numElements = 0;
        // 不要重置tableSize和buckets的大小，保持当前的桶结构
    }
    */

    // 清空哈希表
    void clear() {
        buckets.clear();
        numElements = 0;
        tableSize = 0;     // 重置table大小
    }
};

int main() {
    // 创建一个哈希表实例
    HashTable<int, int> hashTable;

    int N;
    std::cin >> N;
    getchar(); // 吃掉换行符

    std::string line;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int key;
        int value;

        if (command == "insert") {
            iss >> key >> value;
            hashTable.insert(key, value);
        }

        if (command == "erase") {
            // 易错点6：删除前检查哈希表是否为空
            if (hashTable.size() == 0) {
                continue;
            }
            iss >> key;
            hashTable.erase(key);
        }

        if (command == "find") {
            // 易错点7：查找前检查哈希表是否为空
            if (hashTable.size() == 0) {
                std::cout << "not exist" << std::endl;
                continue;
            }
            iss >> key;
            int *res = hashTable.find(key);
            if (res != nullptr) {
                std::cout << *res << std::endl;
            } else {
                std::cout << "not exist" << std::endl;
            }
        }

        if (command == "print") {
            if (hashTable.size() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                hashTable.print();
            }
        }

        if (command == "size") {
            std::cout << hashTable.size() << std::endl;
        }

        if (command == "clear") {
            hashTable.clear();
        }
    }
    return 0;
}