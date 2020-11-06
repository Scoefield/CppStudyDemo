#include <iostream>

using namespace std;

// 纯虚函数和抽象类
class Base
{
private:
    /* data */
public:
    // 纯虚函数，只要有一个纯虚函数，这个类就叫抽象类
    // 抽象类特点：
    // 1.无法示例化对象
    // 2.抽象类的子类必须要重写父类的纯虚函数，否则无法实例化
    virtual void func() = 0;    
};

class Son : public Base
{
private:
    /* data */
public:
    virtual void func()
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    // Base b;  // 抽象类不能实例化
    // b.func(); 

    // Son s;
    // s.func();

    Base *base = new Son;
    base->func();
}

int main()
{
   test01();

   return 0;
}
