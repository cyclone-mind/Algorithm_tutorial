#include <iostream>
#include <vector>
#include "easy-STL/Vector.cpp" // 包含我们修改后的Vector实现

int main() {
    std::cout << "Testing MyVector constructors:" << std::endl;

    // 测试列表初始化
    std::cout << "\n1. Testing initializer list constructor:" << std::endl;
    MyVector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "v1 (initialized with {1, 2, 3, 4, 5}): ";
    v1.print();

    // 测试大小初始化
    std::cout << "\n2. Testing size constructor:" << std::endl;
    MyVector<int> v2(5); // 创建大小为5的向量
    std::cout << "v2 (size 5, default initialized): ";
    v2.print();
    std::cout << "v2 size: " << v2.getSize() << ", capacity: " << v2.getCapacity() << std::endl;

    // 测试大小和默认值初始化
    std::cout << "\n3. Testing size and value constructor:" << std::endl;
    MyVector<int> v3(5, 10); // 创建大小为5，所有元素为10的向量
    std::cout << "v3 (size 5, all elements 10): ";
    v3.print();
    std::cout << "v3 size: " << v3.getSize() << ", capacity: " << v3.getCapacity() << std::endl;

    // 测试迭代器范围初始化
    std::cout << "\n4. Testing iterator range constructor:" << std::endl;
    std::vector<int> std_vec = {10, 20, 30, 40, 50};
    MyVector<int> v4(std_vec.begin(), std_vec.end());
    std::cout << "v4 (initialized from std::vector {10, 20, 30, 40, 50}): ";
    v4.print();
    std::cout << "v4 size: " << v4.getSize() << ", capacity: " << v4.getCapacity() << std::endl;

    // 测试默认构造函数
    std::cout << "\n5. Testing default constructor:" << std::endl;
    MyVector<int> v5;
    std::cout << "v5 (default constructed): ";
    v5.print();
    std::cout << "v5 size: " << v5.getSize() << ", capacity: " << v5.getCapacity() << std::endl;

    return 0;
}