/*
小明喜欢品尝不同口味的咖啡，他发现每种咖啡都可以加入不同的调料，比如牛奶、糖和巧克力。他决定使用装饰者模式制作自己喜欢的咖啡。 

请设计一个简单的咖啡制作系统，使用装饰者模式为咖啡添加不同的调料。系统支持两种咖啡类型：黑咖啡（Black Coffee）和拿铁（Latte）。

输入描述
多行输入，每行包含两个数字。第一个数字表示咖啡的选择（1 表示黑咖啡，2 表示拿铁），第二个数字表示要添加的调料类型（1 表示牛奶，2 表示糖）。
输出描述
根据每行输入，输出制作咖啡的过程，包括咖啡类型和添加的调料。
输入示例
1 1
2 2
输出示例
Brewing Black Coffee
Adding Milk
Brewing Latte
Adding Sugar
*/
#include <iostream>
#include <memory>
#include <utility>
// 咖啡接口
// 具体的黑咖啡类
// 具体的拿铁类
// 装饰器接口，
// 牛奶装饰器，糖装饰器
/*
小明喜欢品尝不同口味的咖啡，他发现每种咖啡都可以加入不同的调料，比如牛奶、糖和巧克力。他决定使用装饰者模式制作自己喜欢的咖啡。 

请设计一个简单的咖啡制作系统，使用装饰者模式为咖啡添加不同的调料。系统支持两种咖啡类型：黑咖啡（Black Coffee）和拿铁（Latte）。

输入描述
多行输入，每行包含两个数字。第一个数字表示咖啡的选择（1 表示黑咖啡，2 表示拿铁），第二个数字表示要添加的调料类型（1 表示牛奶，2 表示糖）。
输出描述
根据每行输入，输出制作咖啡的过程，包括咖啡类型和添加的调料。
输入示例
1 1
2 2
输出示例
Brewing Black Coffee
Adding Milk
Brewing Latte
Adding Sugar
*/


#include <iostream>
#include <memory> // For std::unique_ptr
#include <utility> // For std::move

// 抽象组件接口：定义咖啡的共同行为
// 1. 由组件以及装饰者继承 
// 2. 核心操作和默认虚析构函数
class Coffee {
public:
    virtual void brew() = 0;
    virtual ~Coffee() = default;
};

// 具体组件：黑咖啡
class BlackCoffee : public Coffee {
public:
    void brew() override { std::cout << "Brewing Black Coffee" << std::endl;}
};

// 具体组件：拿铁
class Latte : public Coffee {
public:
    void brew() override { std::cout << "Brewing Latte" << std::endl;}
};

// 抽象装饰者：所有调料装饰器的基类
// 1. 内部持有一个指向抽象组件的引用或指针 通常是智能指针
// 2. 有一个explicit 的带参数的构造函数，用于接收和初始化被装饰的对象。
// 3. 转发其接口方法（例如 brew()）的调用给它所持有的被装饰对象。
class Decorator : public Coffee {
protected:
    std::unique_ptr<Coffee> decoratedCoffee; // 持有被装饰的咖啡对象，被装饰的对象一般写在接口中，具体的装饰器中不写

public:
    /**
     * @brief 构造函数，初始化被装饰的咖啡对象。
     * @param coffee 被装饰的咖啡对象。
     */
    explicit Decorator(std::unique_ptr<Coffee> coffee) : decoratedCoffee(std::move(coffee)) {}

    void brew() override {
        if (decoratedCoffee) {
            decoratedCoffee->brew();
        }
    }
    // 析构函数由基类处理，这里不需要特殊实现
};

// 具体装饰者：牛奶
// 1. 也有一个带参数的构造函数，将传入的组件传递给基类的构造函数
// 2. 重写抽象组件接口方法时，会先调用基类的方法（从而调用被装饰对象的原始方法），然后再添加自己的额外功能。
class MilkDecorator : public Decorator {
public:
    /**
     * @brief 构造函数，用牛奶装饰咖啡。
     * @param coffee 被装饰的咖啡对象。
     */
    explicit MilkDecorator(std::unique_ptr<Coffee> coffee) : Decorator(std::move(coffee)) {}

    /**
     * @brief 制作咖啡并添加牛奶。
     */
    void brew() override {
        Decorator::brew(); // 首先调用基类的brew方法（即被装饰对象的brew方法）
        std::cout << "Adding Milk" << std::endl;
    }
};

// 具体装饰者：糖
class SugarDecorator : public Decorator {
public:
    /**
     * @brief 构造函数，用糖装饰咖啡。
     * @param coffee 被装饰的咖啡对象。
     */
    explicit SugarDecorator(std::unique_ptr<Coffee> coffee) : Decorator(std::move(coffee)) {}

    /**
     * @brief 制作咖啡并添加糖。
     */
    void brew() override {
        Decorator::brew(); // 首先调用基类的brew方法
        std::cout << "Adding Sugar" << std::endl;
    }
};

// 客户端代码
int main() {
    int coffeeType, condimentType;
    // 循环读取输入，直到文件结束或输入错误
    while (std::cin >> coffeeType >> condimentType) {
        std::unique_ptr<Coffee> coffee; // 使用智能指针管理咖啡对象

        // 根据输入选择咖啡类型
        if (coffeeType == 1) {
            coffee = std::make_unique<BlackCoffee>();
        } else if (coffeeType == 2) {
            coffee = std::make_unique<Latte>();
        } else {
            std::cout << "Invalid coffee type" << std::endl;
            continue; // 无效输入，继续下一次循环
        }

        // 根据输入添加调料
        if (condimentType == 1) {
            // 使用std::move将所有权从当前coffee转移到新的MilkDecorator
            coffee = std::make_unique<MilkDecorator>(std::move(coffee));
        } else if (condimentType == 2) {
            // 使用std::move将所有权从当前coffee转移到新的SugarDecorator
            coffee = std::make_unique<SugarDecorator>(std::move(coffee));
        } else {
            std::cout << "Invalid condiment type" << std::endl;
            continue; // 无效输入，继续下一次循环
        }

        // 输出制作过程
        coffee->brew();
    }

    return 0;
}