#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief 购物车管理器单例类
 *
 * 单例模式实现要点：
 * 1. 构造函数和析构函数私有化，防止外部创建实例
 * 2. 删除拷贝构造和赋值操作符，防止复制实例
 * 3. 提供一个全局访问点获取唯一实例
 * 4. 确保线程安全的实例创建
 *
 * C++实现单例模式的注意点：
 * 1. 使用局部静态变量实现懒汉式单例，C++11后保证线程安全
 * 2. 使用delete关键字显式禁用拷贝构造和赋值操作
 * 3. 注意内存泄漏问题，可以使用智能指针管理实例
 * 4. 考虑在多线程环境下的安全性
 */
class ShoppingCartManager {
  private:
    ShoppingCartManager() {};  // 构造函数私有化，防止外部创建实例
    ~ShoppingCartManager() {}; // 析构函数私有化，防止外部删除实例
    // 删除拷贝构造函数和赋值操作符，防止实例被复制
    ShoppingCartManager(const ShoppingCartManager &) = delete;
    ShoppingCartManager &operator=(const ShoppingCartManager &) = delete;

    std::vector<std::pair<std::string, int>> cart; // 存储购物车商品和数量

  public:
    /**
     * @brief 获取购物车单例实例的全局访问点
     *
     * 使用局部静态变量实现懒汉式单例模式
     * C++11标准保证静态局部变量的初始化是线程安全的
     *
     * @return ShoppingCartManager& 返回单例实例的引用
     */
    static ShoppingCartManager &getCart() {
        static ShoppingCartManager
            instance; // 局部静态变量，线程安全的懒汉式实现
        return instance;
    }

    /**
     * @brief 添加商品到购物车
     *
     * @param itemName 商品名称
     * @param num 商品数量
     */
    void addToCart(const std::string &itemName, int num) {
        bool found = false;
        for (auto &item : cart) {
            if (item.first == itemName) {
                item.second += num;
                found = true;
                break;
            }
        }
        if (!found) {
            cart.push_back(std::make_pair(itemName, num));
        }
    }

    /**
     * @brief 查看购物车内容
     */
    void viewCart() const {
        for (const auto &item : cart) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }
};

int main() {
    std::string itemName;
    int num;
    // 获取购物车单例实例
    ShoppingCartManager &cart = ShoppingCartManager::getCart();
    while (std::cin >> itemName >> num) {
        cart.addToCart(itemName, num);
    }
    cart.viewCart();
    return 0;
}