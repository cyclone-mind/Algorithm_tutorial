#include <iostream>
#include <vector>

class Block {
  public:
    virtual void produce() = 0;  // 纯虚函数，没有实现，要求子类中必须重写该方法
    virtual ~Block() {}; // 虚析构函数
};

class CircleBlock : public Block {
  public:
    void produce() override { std::cout << "Circle Block" << std::endl; }
};
class SquareBlock : public Block {
    void produce() override { std::cout << "Square Block" << std::endl; }
};

class BlockFactory {
  public:
    virtual Block *createBlock() = 0;
};

class CircleBlockFactory : public BlockFactory {
  public:
    Block *createBlock() { return new CircleBlock(); } // 返回一个基类指针，指向派生类对象，方便后后续统一调用produce函数
};

class SquareBlockFactory : public BlockFactory {
  public:
    Block *createBlock() { return new SquareBlock(); }
};

class BlockFactorySystem {
  private:
    std::vector<Block *> blocks;

  public:
    void produceBlocks(BlockFactory *factory, int quantity) {
        for (int i = 0; i < quantity; i++) {
            Block *block = factory->createBlock();
            blocks.push_back(block);
            block->produce();
        }
    }
    ~BlockFactorySystem() {
        for (Block *block : blocks) {
            delete block; // 删除基类指针对象时，基类的析构函数需要为虚函数
        }
    }
};

int main() {
    // 创建积木工厂系统
    BlockFactorySystem factorySystem;

    // 读取生产次数
    int productionCount;
    std::cin >> productionCount;

    // 读取每次生产的积木类型和数量
    for (int i = 0; i < productionCount; i++) {
        std::string blockType;
        int quantity;
        std::cin >> blockType >> quantity;

        if (blockType == "Circle") {
            factorySystem.produceBlocks(new CircleBlockFactory(), quantity);
        } else if (blockType == "Square") {
            factorySystem.produceBlocks(new SquareBlockFactory(), quantity);
        }
    }

    return 0;
}