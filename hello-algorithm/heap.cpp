#include <iostream>
#include <vector>
#include <stdexcept>

// 使用模板实现堆类，可以存储不同类型的元素
template<typename T>
class Heap {
private:
    std::vector<T> heap;  // 使用vector作为底层存储结构

    // 获取父节点索引
    size_t parent(size_t i) { return (i - 1) / 2; }
    
    // 获取左子节点索引
    size_t leftChild(size_t i) { return 2 * i + 1; }
    
    // 获取右子节点索引
    size_t rightChild(size_t i) { return 2 * i + 2; }
    
    // 交换两个元素
    void swap(size_t i, size_t j) {
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    
    // 向下调整堆（最大堆）
    void heapifyDown(size_t i) {
        size_t largest = i;  // 假设当前节点是最大的
        size_t left = leftChild(i);
        size_t right = rightChild(i);
        
        // 如果左子节点存在且大于当前最大节点
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
            
        // 如果右子节点存在且大于当前最大节点
        if (right < heap.size() && heap[right] > heap[largest])
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
        if (i != 0 && heap[parent(i)] < heap[i]) {
            swap(i, parent(i));
            heapifyUp(parent(i));
        }
    }

public:
    // 构造函数
    Heap() {}
    
    // 向堆中插入元素
    void insert(T key) {
        // 在末尾插入元素
        heap.push_back(key);
        
        // 向上调整堆
        heapifyUp(heap.size() - 1);
    }
    
    // 获取堆顶元素
    T peek() {
        if (heap.empty())
            throw std::underflow_error("Heap is empty");
        return heap[0];
    }
    
    // 删除堆顶元素
    void extractTop() {
        if (heap.empty())
            throw std::underflow_error("Heap is empty");
            
        // 将最后一个元素移到堆顶
        heap[0] = heap.back();
        heap.pop_back();  // 删除最后一个元素
        
        // 向下调整堆
        heapifyDown(0);
    }
    
    // 检查堆是否为空
    bool empty() {
        return heap.empty();
    }
    
    // 获取堆的大小
    size_t size() {
        return heap.size();
    }
    
    // 打印堆中的所有元素
    void prsize_tHeap() {
        for (const T& item : heap) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

// 测试函数
int main() {
    // 创建一个整数类型的堆
    Heap<size_t> size_tHeap;
    
    // 插入一些元素
    size_tHeap.insert(10);
    size_tHeap.insert(20);
    size_tHeap.insert(15);
    size_tHeap.insert(30);
    size_tHeap.insert(40);
    
    std::cout << "整数堆: ";
    size_tHeap.prsize_tHeap();
    
    // 创建一个浮点数类型的堆
    Heap<float> floatHeap;
    
    // 插入一些元素
    floatHeap.insert(3.14f);
    floatHeap.insert(2.71f);
    floatHeap.insert(1.41f);
    floatHeap.insert(1.73f);
    
    std::cout << "浮点数堆: ";
    floatHeap.prsize_tHeap();
    
    // 创建一个字符串类型的堆
    Heap<std::string> stringHeap;
    
    // 插入一些元素
    stringHeap.insert("banana");
    stringHeap.insert("apple");
    stringHeap.insert("cherry");
    stringHeap.insert("date");
    
    std::cout << "字符串堆: ";
    stringHeap.prsize_tHeap();
    
    return 0;
}