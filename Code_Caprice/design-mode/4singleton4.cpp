#include <iostream>
#include <string>
#include <utility>
#include <vector>

class ShoppingCartManager {
  private:
    ShoppingCartManager() {};
    ~ShoppingCartManager() {};
    ShoppingCartManager(const ShoppingCartManager &) = delete;
    ShoppingCartManager &operator=(const ShoppingCartManager &) = delete;
    std::vector<std::pair<std::string, int>> cart;

  public:
    static ShoppingCartManager &getCart() {
        static ShoppingCartManager instance;
        return instance;
    }
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
    void viewCart() const {
        for (const auto &item : cart) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }
};

int main() {
    std::string itemName;
    int num;
    ShoppingCartManager &cart = ShoppingCartManager::getCart();
    while (std::cin >> itemName >> num) {
        cart.addToCart(itemName, num);
    }
    cart.viewCart();
    return 0;
}