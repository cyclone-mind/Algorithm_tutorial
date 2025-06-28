/*
题目描述
小明家新开了两个工厂用来生产家具，一个生产现代风格的沙发和椅子，一个生产古典风格的沙发和椅子，现在工厂收到了一笔订单，请你帮他设计一个系统，描述订单需要生产家具的信息。
输入描述
输入的第一行是一个整数 N（1 ≤ N ≤ 100），表示订单的数量。

接下来的 N 行，每行输入一个字符串，字符串表示家具的类型。家具类型分为 "modern"
和 "classical" 两种。

输出描述
对于每笔订单，输出字符串表示该订单需要生产家具的信息。

modern订单会输出下面两行字符串

modern chair

modern sofa

classical订单会输出下面两行字符串

classical chair

classical soft

输入示例
3
modern
classical
modern
输出示例
modern chair
modern sofa
classical chair
classical sofa
modern chair
modern sofa
*/
#include <iostream>
#include <string>

using namespace std;

class Chair {
  public:
    virtual void showInfo() = 0;
};
class Sofa {
  public:
    virtual void showInfo() = 0;
};
class ModernChair : public Chair {
  public:
    void showInfo() override { cout << "modern chair" << endl; }
};
class ModernSofa : public Sofa {
  public:
    void showInfo() override { cout << "modern sofa" << endl; }
};
class ClassicalChair : public Chair {
  public:
    void showInfo() override { cout << "classical chair" << endl; }
};
class ClassicalSofa : public Sofa {
  public:
    void showInfo() override { cout << "classical sofa" << endl; }
};
class Factory {
  public:
    virtual Chair *createChair() = 0;
    virtual Sofa *createSofa() = 0;
};

class ModernFactory : public Factory {
  public:
    Chair *createChair() override { return new ModernChair(); }
    Sofa *createSofa() override { return new ModernSofa(); }
};

class ClassicalFactory : public Factory {
  public:
    Chair *createChair() override { return new ClassicalChair(); }
    Sofa *createSofa() override { return new ClassicalSofa(); }
};

int main() {
    int orderQuantity;
    cin >> orderQuantity;
    for (int i = 0; i < orderQuantity; i++) {
        string orderType;
        cin >> orderType;
        Factory *factory = nullptr; // 先创建一个工厂指针，然后再根据情况指向具体哪个工厂
        if (orderType == "modern") {
            factory = new ModernFactory();
        } else if (orderType == "classical") {
            factory = new ClassicalFactory();
        }
        Chair *chair = factory->createChair();
        Sofa *sofa = factory->createSofa();
        chair->showInfo();
        sofa->showInfo();
    }
}