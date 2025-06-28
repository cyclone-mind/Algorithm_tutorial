/*
小明想要购买一套房子，他决定寻求一家房屋中介来帮助他找到一个面积超过100平方米的房子，只有符合条件的房子才会被传递给小明查看。
输入描述
第一行是一个整数 N（1 ≤ N ≤ 100），表示可供查看的房子的数量。

接下来的 N 行，每行包含一个整数，表示对应房子的房屋面积。

输出描述
对于每个房子，输出一行，表示是否符合购房条件。如果房屋面积超过100平方米，输出
"YES"；否则输出 "NO"。 输入示例
3
120
80
110
输出示例
YES
NO
YES
*/

/*
1. 定义抽象主题, 一般是接口或者抽象类，声明真实主题和代理对象实现的业务方法。
2. 定义真实主题，实现抽象主题中的具体业务
3. 定义代理类，包含对RealSubject的引用，并提供和真实主题相同的接口，
这样代理就可以替代真实主题，并对真实主题进行功能扩展。
4. 客户端使用代理
*/
#include <iostream>

/**
 * @brief 抽象主题：定义真实主题和代理对象共同实现的业务接口。
 *        在本例中，表示房屋购买的抽象行为。
 */
class HousePurchase {
  public:
    /**
     * @brief 购买房屋的抽象方法。
     * @param area 房屋面积。
     */
    virtual void purchaseHouse(int area) = 0;
    virtual ~HousePurchase() {};
};

/**
 * @brief 真实主题：实现了抽象主题接口的具体业务逻辑。
 *        在本例中，表示小明（真实的购房者）的行为。
 */
class HouseBuyer : public HousePurchase {
  public:
    /**
     * @brief 真实购房者购买房屋的方法。
     *        小明只会看到符合要求的房子，所以直接输出YES。
     * @param area 房屋面积。
     */
    void purchaseHouse(int area) override { std::cout << "YES" << std::endl; }
};

/**
 * @brief 代理类：包含对真实主题的引用，并提供和真实主题相同的接口，
 *        这样代理就可以替代真实主题，并对真实主题进行功能扩展。
 *        在本例中，代理（房屋中介）负责筛选房屋，只将符合条件的房屋传递给小明。
 */
class HouseAgentProxy : public HousePurchase {
  private:
    HouseBuyer realBuyer; // 真实购房者对象，代理持有一个真实对象的实例

  public:
    /**
     * @brief 代理购买房屋的方法，用于在将房屋信息传递给真实购房者之前进行筛选。
     * @param area 房屋面积。
     */
    void purchaseHouse(int area) override {
        if (area > 100) { // 如果房屋面积超过100平方米，则符合条件，交给小明购买
            realBuyer.purchaseHouse(area);
        } else {
            std::cout
                << "NO"
                << std::endl; // 代理发现不满足条件，则不会交给小明（输出NO）
        }
    }
};

int main() {
    int numHouses; // 表示可供查看的房屋数量
    std::cin >> numHouses;

    HouseAgentProxy agentProxy; // 创建房屋中介代理对象

    for (int i = 0; i < numHouses; i++) {
        int currentArea; // 当前房屋的面积
        std::cin >> currentArea;
        agentProxy.purchaseHouse(currentArea); // 代理处理当前房屋
    }
    return 0;
}