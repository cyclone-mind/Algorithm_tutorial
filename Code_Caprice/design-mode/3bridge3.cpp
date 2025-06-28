/*
题目描述
小明家有一个万能遥控器，能够支持多个品牌的电视。每个电视可以执行开机、关机和切换频道的操作，请你使用桥接模式模拟这个操作。
输入描述
第一行是一个整数 N（1 <= N <= 100），表示后面有 N 行输入。

接下来的 N
行，每行包含两个数字。第一个数字表示创建某个品牌的遥控和电视，第二个数字表示执行的操作。

其中，0 表示创建 Sony 品牌的电视，1 表示创建 TCL 品牌的遥控和电视；

2 表示开启电视、3表示关闭电视，4表示切换频道。

输出描述
对于每个操作，输出相应的执行结果。
输入示例
6
0 2
1 2
0 4
0 3
1 4
1 3
输出示例
Sony TV is ON
TCL TV is ON
Switching Sony TV channel
Sony TV is OFF
Switching TCL TV channel
TCL TV is OFF
*/

#include <iostream>
#include <vector>
class TV {
  public:
    virtual ~TV() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void switchChannel() = 0;
};

class SonyTV : public TV {
  public:
    void turnOn() override { std::cout << "Sony TV is ON" << std::endl; }
    void turnOff() override { std::cout << "Sony TV is OFF" << std::endl; }
    void switchChannel() override {
        std::cout << "Switching Sony TV channel" << std::endl;
    }
};

class TCLTV : public TV {
  public:
    void turnOn() override { std::cout << "TCL TV is ON" << std::endl; }
    void turnOff() override { std::cout << "TCL TV is OFF" << std::endl; }
    void switchChannel() override {
        std::cout << "Switching TCL TV channel" << std::endl;
    }
};

class RemoteControl {
  protected:
    TV *tv;

  public:
    RemoteControl(TV *tv) : tv(tv) {}
    ~RemoteControl() = default;

    // 遥控器的高层操作，它会将请求委托给具体的电视机对象
    virtual void powerOn() { tv->turnOn(); }

    virtual void powerOff() { tv->turnOff(); }

    virtual void nextChannel() { tv->switchChannel(); }
};

int main() {
    int N;
    std::cin >> N;
    std::vector<TV *> tvs;
    tvs.push_back(new SonyTV);
    tvs.push_back(new TCLTV);
    for (int i = 0; i < N; i++) {
        int type, operation;
        std::cin >> type >> operation;
        if (type == 0 || type == 1) {
            RemoteControl remote(tvs[type]);
            switch (operation) {
            case 2:
                remote.powerOn();
                break;
            case 3:
                remote.powerOff();
                break;
            case 4:
                remote.nextChannel();
                break;
            }
        }
    }

    for (TV *tv : tvs) {
        delete tv;
    }

    return 0;
}
