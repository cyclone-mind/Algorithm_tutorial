/*
题目描述
小明家的电源总开关控制了家里的三个设备：空调、台灯和电视机。每个设备都有独立的开关密码，分别用数字1、2和3表示。即输入1时，空调关闭，输入2时，台灯关闭，输入3时，电视机关闭，当输入为4时，表示要关闭所有设备。请你使用外观模式编写程序来描述电源总开关的操作。

输入描述
第一行是一个整数 N（1 <= N <= 100），表示后面有 N 行输入。

 接下来的 N
行，每行包含一个数字，表示对应设备的开关操作（1表示关闭空调，2表示关闭台灯，3表示关闭电视机，4表示关闭所有设备）。

输出描述
输出关闭所有设备后的状态，当输入的数字不在1-4范围内时，输出Invalid device code.
输入示例
4
1
2
3
4
输出示例
Air Conditioner is turned off.
Desk Lamp is turned off.
Television is turned off.
All devices are off.
*/
#include <iostream>
#include <vector>

class AirConditioner {
public:
    void turnOff() {
        std::cout << "Air Conditioner is turned off." << std::endl;
    }
};

class DeskLamp {
public:
    void turnOff() {
        std::cout << "Desk Lamp is turned off." << std::endl;
    }
};

class Television {
public:
    void turnOff() {
        std::cout << "Television is turned off." << std::endl;
    }
};

class PowerSwitchFacade {
private:
    AirConditioner& airConditioner; // 注意这里是引用类型 `&`
    DeskLamp& deskLamp;
    Television& television;

public:

    PowerSwitchFacade(AirConditioner& ac, DeskLamp& dl, Television& tv)
        : airConditioner(ac), deskLamp(dl), television(tv) {
    }

    void turnOffDevice(int deviceCode) {
        switch (deviceCode) {
            case 1:
                airConditioner.turnOff();
                break;
            case 2:
                deskLamp.turnOff();
                break;
            case 3:
                television.turnOff();
                break;
            case 4:
                // 这里按题目要求只输出一句话，实际应用中会调用各个设备的关闭方法
                std::cout << "All devices are off." << std::endl;
                break;
            default:
                std::cout << "Invalid device code." << std::endl;
        }
    }
};

int main() {
    // 读取输入
    int n;
    std::cin >> n;
    std::vector<int> input(n);

    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    // 在外部创建子系统对象
    AirConditioner myAirConditioner;
    DeskLamp myDeskLamp;
    Television myTelevision;

    // 创建电源总开关外观，并将子系统对象的引用传入
    PowerSwitchFacade powerSwitch(myAirConditioner, myDeskLamp, myTelevision);

    // 执行操作
    for (int i = 0; i < n; i++) {
        powerSwitch.turnOffDevice(input[i]);
    }

    return 0;
}
