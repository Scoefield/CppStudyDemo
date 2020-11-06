#include <iostream>

using namespace std;

// 多态的案例：制作饮料
class AbstractDrinking
{
public:
    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 倒入杯中
    virtual void PourInCup() = 0;

    // 加入辅料   
    virtual void PutSomething() = 0;

    // 制作饮品
    void makeDrunk()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Caffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }

    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶" << endl;
    }
};

// 制作柠檬茶
class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }

    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入柠檬" << endl;
    }

};

// 制作函数
void doWork(AbstractDrinking * abs)
{
    abs-> makeDrunk();
    delete abs;     // 记得释放
}

void test01()
{
    // 制作咖啡
    Caffee *caffee = new Caffee;
    doWork(caffee);

    cout << "-----------" << endl;

    // 制作柠檬茶
    Tea *tea = new Tea;
    doWork(tea);
}


int main()
{
   test01();

   return 0;
}
