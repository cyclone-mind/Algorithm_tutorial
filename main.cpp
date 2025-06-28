#include <cstdint>
#include <cstring>
#include <iostream>

class String {
  public:
    String() = default;
    String(const char *string) {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, string, m_Size);
        m_Data[m_Size] = '\0';
    }

    String(const String &other) {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, other.m_Data, m_Size + 1);
    }

    String(String &&other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    ~String() { delete[] m_Data; }

    void Print() {
        if (m_Data)
            printf("%s\n", m_Data);
    }

  private:
    char *m_Data = nullptr;
    uint32_t m_Size = 0;
};

class Entity {
  public:
    Entity(const String &name) : m_Name(name) {
        printf("Entity created with L-value!\n");
    }
    Entity(String &&name) : m_Name(std::move(name)) {
        printf("Entity created with R-value!\n");
    }
    void PrintName() { m_Name.Print(); }

  private:
    String m_Name;
};

int main(int argc, const char *argv[]) {
    printf("--- 1. 使用临时对象(右值)构造 entity ---\n");
    Entity entity(String("Cherno"));
    entity.PrintName();

    printf("\n--- 2. 使用具名对象(左值)构造 entity2 ---\n");
    String appName = "App";
    Entity entity2(appName);
    entity2.PrintName();

    return 0;
}