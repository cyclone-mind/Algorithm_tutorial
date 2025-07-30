#include <iostream>
#include <vector>
#include <stdexcept>

// 自定义 priority_queue 实现
template<typename T>
class CustomPriorityQueue {
private:
    std::vector<T> data;  // 使用vector作为底层存储结构

    // 获取父节点索引
    size_t parent(size_t i) { return (i - 1) / 2; }
    
    // 获取左子节点索引
    size_t leftChild(size_t i) { return 2 * i + 1; }
    
    // 获取右子节点索引
    size_t rightChild(size_t i) { return 2 * i + 2; }
    
    // 交换两个元素
    void swap(size_t i, size_t j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    
    // 向下调整堆（最大堆）
    void heapifyDown(size_t i) {
        size_t largest = i;  // 假设当前节点是最大的
        size_t left = leftChild(i);
        size_t right = rightChild(i);
        
        // 如果左子节点存在且大于当前最大节点
        if (left < data.size() && data[left] > data[largest])
            largest = left;
            
        // 如果右子节点存在且大于当前最大节点
        if (right < data.size() && data[right] > data[largest])
            largest = right;
            
        // 如果最大节点不是当前节点，则交换并继续调整
        if (largest != i) {
            swap(i, largest);
            heapifyDown(largest);
        }
    }
    
    // 向上调整堆
    void heapifyUp(size_t i) {
        // 如果不是根节点且父节点小于当前节点
        if (i != 0 && data[parent(i)] < data[i]) {
            swap(i, parent(i));
            heapifyUp(parent(i));
        }
    }

public:
    // 构造函数
    CustomPriorityQueue() {}
    
    // 析构函数
    ~CustomPriorityQueue() {}
    
    // 将元素添加到 priority_queue 中
    void push(const T& key) {
        // 在末尾插入元素
        data.push_back(key);
        
        // 向上调整堆
        heapifyUp(data.size() - 1);
    }
    
    // 弹出 priority_queue 中的最大元素
    void pop() {
        if (data.empty())
            throw std::underflow_error("Priority queue is empty");
            
        // 将最后一个元素移到堆顶
        data[0] = data.back();
        data.pop_back();  // 删除最后一个元素
        
        // 向下调整堆
        if (!data.empty()) {
            heapifyDown(0);
        }
    }
    
    // 获取 priority_queue 中的最大元素
    T top() {
        if (data.empty())
            throw std::underflow_error("Priority queue is empty");
        return data[0];
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
    CustomPriorityQueue<int> pq;
    
    // 添加一些元素
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(40);
    
    std::cout << "Priority queue 大小: " << pq.size() << std::endl;
    
    // 弹出并打印所有元素
    std::cout << "弹出元素: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
    
    // 验证是否为空
    std::cout << "Priority queue 是否为空: " << (pq.empty() ? "是" : "否") << std::endl;
    
    return 0;
}