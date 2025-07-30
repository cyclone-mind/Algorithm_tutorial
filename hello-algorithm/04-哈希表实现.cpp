#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Pair {
  public:
    int key;
    std::string val;
    Pair(int key, std::string val) : key(key), val(val) {};
};

class ArrayHashMap {
  private:
    std::vector<std::optional<Pair>> buckets;

  public:
    // 构造函数，初始化哈希表大小
    ArrayHashMap(int capacity = 100) : buckets(capacity, std::nullopt) {}

    // 哈希函数
    int hashFunc(int key) { return key % buckets.size(); }

    // 插入操作
    void put(int key, const std::string &val) {
        int index = hashFunc(key);
        buckets[index] = Pair(key, val);
    }

    // 查询操作
    std::optional<std::string> get(int key) {
        int index = hashFunc(key);
        if (buckets[index].has_value() && buckets[index]->key == key) {
            return buckets[index]->val;
        }
        return std::nullopt;
    }

    // 删除操作
    void remove(int key) {
        int index = hashFunc(key);
        if (buckets[index].has_value() && buckets[index]->key == key) {
            buckets[index] = std::nullopt;
        }
    }

    // 获取所有键值对
    std::vector<Pair> pairSet() {
        std::vector<Pair> res;
        for (auto &bucket : buckets) {
            if (bucket.has_value()) {
                res.push_back(bucket.value());
            }
        }
        return res;
    }

    // 获取所有键
    std::vector<int> keySet() {
        std::vector<int> res;
        for (auto &bucket : buckets) {
            if (bucket.has_value()) {
                res.push_back(bucket->key);
            }
        }
        return res;
    }

    // 获取所有值
    std::vector<std::string> valueSet() {
        std::vector<std::string> res;
        for (auto &bucket : buckets) {
            if (bucket.has_value()) {
                res.push_back(bucket->val);
            }
        }
        return res;
    }

    // 打印哈希表
    void print() {
        for (const auto &p : pairSet()) {
            std::cout << p.key << " -> " << p.val << std::endl;
        }
    }
};

int main() {
    ArrayHashMap hashMap(10);

    // 测试插入和查询
    hashMap.put(1, "apple");
    hashMap.put(2, "banana");

    auto result = hashMap.get(1);
    if (result.has_value()) {
        std::cout << "Key 1: " << result.value() << std::endl;
    }

    std::cout << "\n--- 所有键值对 ---" << std::endl;
    hashMap.print();

    std::cout << "\n--- 所有键 ---" << std::endl;
    for (int key : hashMap.keySet()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- 所有值 ---" << std::endl;
    for (const auto &val : hashMap.valueSet()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 测试删除
    hashMap.remove(2);
    std::cout << "\n--- 删除键为 2 的条目后 ---" << std::endl;
    hashMap.print();

    return 0;
}