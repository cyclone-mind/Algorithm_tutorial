/*
题目描述
公司正在开发一个图形设计软件，其中有一个常用的图形元素是矩形。设计师在工作时可能需要频繁地创建相似的矩形，而这些矩形的基本属性是相同的（颜色、宽度、高度），为了提高设计师的工作效率，请你使用原型模式设计一个矩形对象的原型。使用该原型可以快速克隆生成新的矩形对象。

输入描述
首先输入一个字符串，表示矩形的基本属性信息，包括颜色、长度和宽度，用空格分隔，例如
"Red 10 5"。

然后输入一个整数 N（1 ≤ N ≤ 100），表示使用原型创建的矩形数量。

输出描述
对于每个矩形，输出一行字符串表示矩形的详细信息，如 "Color: Red, Width:
10,Height: 5"。 输入示例 Red 10 5
3
输出示例
Color: Red, Width: 10, Height: 5
Color: Red, Width: 10, Height: 5
Color: Red, Width: 10, Height: 5
提示信息
使用原型模式中的克隆方法实现矩形对象的创建。
*/

/*
原型模式的实现过程即上面描述模块的实现过程：
·创建一个抽象类或接口，声明一个克隆方法clone
·实现具体原型类，该原型类又复杂的构造方法，重写克隆方法，克隆方法本质是调用拷贝构造函数，拷贝构造函数
·客户端中实例化具体原型类的对象，并调用其克隆方法来创建新的对象。
*/
#include <iostream>
#include <string>

using namespace std;
// 定义克隆接口
class Prototype {
  public:
    virtual Prototype *clone() = 0;
    virtual void display() const = 0;
    virtual ~Prototype() {};
};

class Rectangle : public Prototype {
  private:
    string color;
    int width;
    int height;

  public:
    // 构造函数
    Rectangle(string c, int w, int h) : color(c), width(w), height(h) {}  // 构造函数主体中有复杂的操作，生成复杂状态，这里省略没有写

    Rectangle(const Rectangle &orther)
        : color(orther.color), width(orther.width), height(orther.height) {} // 拷贝构造函数中直接将复杂状态以初始化列表的方式进行初始化，这里省略没有写
    // 克隆方法 - 核心！
    Rectangle *clone() override { return new Rectangle(*this); }

    // 显示信息
    void display() const override {
        cout << "Color: " << color << ", Width: " << width
             << ", Height: " << height << endl;
    }
};
int main() {
    // 读取原型属性
    string color;
    int width, height, n;
    cin >> color >> width >> height >> n;

    // 创建原型对象
    Rectangle *prototype = new Rectangle(color, width, height);

    // 使用原型克隆N个对象
    for (int i = 0; i < n; i++) {
        Rectangle *clone = prototype->clone();
        clone->display();
        delete clone;
    }

    delete prototype;
    return 0;
}