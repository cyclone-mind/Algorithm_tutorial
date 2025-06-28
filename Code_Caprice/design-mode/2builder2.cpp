/*
4. 自行车加工
题目描述
小明家新开了一家自行车工厂，用于使用自行车配件（车架 frame 和车轮 tires
）进行组装定制不同的自行车，包括山地车和公路车。

山地车使用的是Aluminum Frame（铝制车架）和 Knobby
Tires（可抓地轮胎），公路车使用的是 Carbon Frame （碳车架）和 Slim Tries。

现在它收到了一笔订单，要求定制一批自行车，请你使用【建造者模式】告诉小明这笔订单需要使用那些自行车配置吧。



输入描述
输入的第一行是一个整数 N（1 ≤ N ≤ 100），表示订单的数量。

接下来的 N 行，每行输入一个字符串，字符串表示客户的自行车需求。

字符串可以包含关键词 "mountain" 或 "road"，表示客户需要山地自行车或公路自行车。

输出描述
对于每笔订单，输出该订单定制的自行车配置。
输入示例
3
mountain
road
mountain
输出示例
Aluminum Frame Knobby Tires
Carbon Frame Slim Tires
Aluminum Frame Knobby Tires
提示信息
在本例中：产品为自行车，可以有两个建造者：山地车建造者和公路车建造者。
*/

// 1.定义产品类：产品类应该包含多个组成部分，这些部分的属性和方法构成了产品的接口
// 2.定义抽象建造者接口：创建一个接口，包含构建产品各个部分的抽象方法。这些方法通常用于设置产品的各个属性。
// 3. 创建具体建造者：实现抽象建造者接口，构建具体的产品。
// 4. 定义Director类： 指导者类来控制构建产品的顺序和步骤。
// 5.客户端使用建造者模式：在客户端中创建【具体建造者对象】和【指导者对象】，通过指导者来构建产品。
#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class Bike {
  public:
    string frame;
    string tires;
    void setFrame(const string &frame) { this->frame = frame; }
    void setTires(const string &tires) { this->tires = tires; }
    friend ostream &operator<<(ostream &os, const Bike &bike) {
        os << bike.frame << " " << bike.tires;
        return os;
    }
};
class BikeBuilder {
  public:
    virtual ~BikeBuilder() = default; // 虚析构函数确保正确销毁派生类对象
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getResult() = 0;
};
class MountainBikeBuilder : public BikeBuilder {
  public:
    Bike bike;
    void buildFrame() override { bike.setFrame("Aluminum Frame"); }
    void buildTires() override { bike.setTires("Knobby Tires"); }
    Bike getResult() override { return bike; }
};
class RoadBikeBuilder : public BikeBuilder {
  public:
    Bike bike;
    void buildFrame() override { bike.setFrame("Carbon Frame"); }
    void buildTires() override { bike.setTires("Slim Tires"); }
    Bike getResult() override { return bike; }
};
class BikeDirector {
  public:
    Bike constructBike(BikeBuilder &builder) {
        builder.buildFrame();
        builder.buildTires();
        return builder.getResult();
    }
};
int main() {
    int orderQuantity;
    std::cin >> orderQuantity;
    BikeDirector director;
    for (int i = 0; i < orderQuantity; i++) {
        string bikeType;
        std::cin >> bikeType;
        BikeBuilder *builder;
        if (bikeType == "mountain") {
            builder = new MountainBikeBuilder();
        } else if (bikeType == "road") {
            builder = new RoadBikeBuilder();
        }
        Bike bike = director.constructBike(*builder);
        std::cout << bike << endl;
        delete builder;
    }
    return 0;
}