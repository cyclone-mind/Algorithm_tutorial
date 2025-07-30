

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
template <typename T> class MyVector {
  private:
    T *elements;
    size_t size;
    size_t capacity;

  public:
  void reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        T *newelements = new T[newCapacity];
        if (elements != nullptr) {
            std::copy(elements, elements + size, newelements);
        }
        delete[] elements;
        elements = newelements;
        capacity = newCapacity;
    }
}
    MyVector() : elements(nullptr), size(0), capacity(0) {}
    ~MyVector() { delete[] elements; }

    MyVector(std::initializer_list<T> list): elements(nullptr),size(0),capacity(0){
        reserve(list.size()*2);
        size = list.size();
        std::copy(list.begin(),list.end(),elements);
    }
    explicit MyVector(size_t count) : elements(nullptr),size(0),capacity(0) {
        reserve(count);
        for(size_t i = 0;i < count;i++){
            new (elements + i) T();
        }
        size = count;
    }
    MyVector(size_t count,const T& value) : elements(nullptr),size(0),capacity(0) {
        reserve(count);
        std::fill(elements,elements+count,value);
        size = count;
    }
    MyVector(const MyVector &orther) : size(orther.size), capacity(orther.capacity) {
        if (capacity > 0) {
            elements = new T[capacity];
            std::copy(orther.elements, orther.elements + orther.size, elements);
        } else {
            elements = nullptr;
        }
    }
    MyVector &operator=(const MyVector &orther) {
        if (this != orther) {
            delete[] elements;
            size = orther.size;
            capacity = orther.capacity;
            if (orther.capacity > 0) {
                elements = new T[orther.capacity];
                std::copy(orther.elements, orther.elements + orther.size,
                          elements);
            } else {
                elements = nullptr;
            }
        }
    }


    void push_back(const T &value) {
        if (size == capacity)
            reserve(capacity == 0 ? 1 : capacity * 2);
        elements[size++] = value;
    }
    void pop_back() {
        if (size > 0)
            --size;
    }
    void insert(const size_t index, const T &value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity)
            reserve(capacity == 0 ? 1 : capacity * 2);
        for (size_t i = size; i > index; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index] = value;
        size++;
    }
    size_t getSize() const { return size; }
    size_t empty() const { return size == 0; }
    size_t getCapacity() const { return capacity; }
    T get(const size_t index) const {
        if(index >= size) { return -1;}
        return elements[index];
    }
    T &operator[](const size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    const T &operator[](const size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    void clear(){
        size = 0;
    }
    T *begin() { return elements; }
    T *end() { return elements + size; }
    const T *begin() const { return elements; }
    const T *end() const { return elements + size; }
};