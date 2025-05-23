#include <iostream>

class Rectangle {

private:
int m_width;
int m_height;
public:
Rectangle(int width, int height) : m_width(width), m_height(height){
std::cout << "Rectangle object created." << std::endl;
}
~Rectangle(){
	std::cout << "Rectangle object destroyed." << std::endl;
}
int getWidth() const {
	return m_width;
}
int getHeight() const {
	return m_height;
}

void setWidth(int w){
	this->m_width = w;
}

void setHeight(int h){
	this->m_height = h;
}

};

int main() {
    std::cout << "--- Stack Object ---" << std::endl;
    {
        Rectangle stackRect(10, 20); // 栈对象，在作用域结束时自动销毁
        std::cout << "Stack object area: " << stackRect.getWidth() * stackRect.getHeight() << std::endl;
    } // stackRect goes out of scope here
    std::cout << "--- Stack Object Scope Ended ---" << std::endl;

    std::cout << "\n--- Heap Object ---" << std::endl;
    // 在堆上创建 Rectangle 对象，并使用指针接收
    Rectangle* heapRect = nullptr;
    // Use new to create object on heap

    if (heapRect != nullptr) {
        // Access members using arrow operator
        std::cout << "Heap object area: " << heapRect->getWidth() * heapRect->getHeight() << std::endl;
        // Explicitly delete the heap object
        // Use delete keyword here
    }
    std::cout << "--- Heap Object Management Ended ---" << std::endl;


    std::cout << "\nProgram finished." << std::endl;
    return 0;
}