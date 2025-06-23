#include <iostream>

// Singleton 类定义
class Singleton {
  private:
    // 私有构造函数，防止外部直接实例化
    Singleton() {
        std::cout << "Singleton 实例已创建 (局部静态变量方式)." << std::endl;
    }

    // 私有析构函数
    ~Singleton() {
        std::cout << "Singleton 实例已销毁 (局部静态变量方式)." << std::endl;
    }

    // 禁用拷贝构造函数
    Singleton(const Singleton &) = delete;
    // 禁用赋值运算符
    Singleton &operator=(const Singleton &) = delete;

  public:
    // 公共静态方法，用于获取单例实例的引用
    static Singleton &getInstance() {
        // 局部静态变量，在第一次调用时初始化，且初始化过程是线程安全的
        static Singleton instance;
        return instance;
    }

    // 示例方法，展示单例功能
    void showMessage() const {
        std::cout << "你好，我是单例实例（来自局部静态变量方式）！"
                  << std::endl;
    }
};

int main() {
    std::cout << "--- 获取单例实例 (局部静态变量方式) ---" << std::endl;

    // 获取第一个单例实例
    Singleton &s1 = Singleton::getInstance();
    std::cout << "s1 的地址: " << &s1 << std::endl;
    s1.showMessage();

    // 获取第二个单例实例
    Singleton &s2 = Singleton::getInstance();
    std::cout << "s2 的地址: " << &s2 << std::endl;
    s2.showMessage();

    // 验证 s1 和 s2 是否是同一个实例
    if (&s1 == &s2) {
        std::cout << "s1 和 s2 是同一个实例！✨" << std::endl;
    } else {
        std::cout << "s1 和 s2 不是同一个实例！⚠️" << std::endl;
    }

    std::cout << "\n程序执行完毕." << std::endl;
    // 局部静态变量会在程序结束时自动销毁，无需手动 cleanup
    return 0;
}