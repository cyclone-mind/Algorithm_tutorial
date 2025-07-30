#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

// 使用 STL heap 函数实现的 priority_queue
template<typename T>
class STLHeapPriorityQueue {
private:
    std::vector<T> data;  // 使用vector作为底层存储结构

public:
    // 构造函数
    STLHeapPriorityQueue() {}
    
    // 析构函数
    ~STLHeapPriorityQueue() {}
    
    // 将元素添加到 priority_queue 中
    void push(const T& key) {
        // 在末尾插入元素
        data.push_back(key);
        
        // 使用 std::push_heap 重新构造堆
        std::push_heap(data.begin(), data.end());
    }
    
    // 弹出 priority_queue 中的最大元素
    void pop() {
        if (data.empty())
            throw std::underflow_error("Priority queue is empty");
            
        // 使用 std::pop_heap 将最大元素移到末尾
        std::pop_heap(data.begin(), data.end());
        
        // 删除末尾元素
        data.pop_back();
    }
    
    // 获取 priority_queue 中的最大元素
    T top() {
        if (data.empty())
            throw std::underflow_error("Priority queue is empty");
        return data.front();
    }
    
    // 获取 priority_queue 中元素的个数
    size_t size() {
        return data.size();
    }
    
    // 判断 priority_queue 是否为空
    bool empty() {
        return data.empty();
    }
};

// 测试函数
int main() {
    // 创建一个整数类型的 priority_queue
    STLHeapPriorityQueue<int> pq;
    
    // 添加一些元素
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(40);
    
    std::cout << "STL heap priority queue 大小: " << pq.size() << std::endl;
    
    // 弹出并打印所有元素
    std::cout << "弹出元素: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
    
    // 验证是否为空
    std::cout << "STL heap priority queue 是否为空: " << (pq.empty() ? "是" : "否") << std::endl;
    
    return 0;
}