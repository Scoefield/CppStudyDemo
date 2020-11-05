#include <iostream>

using namespace std;

// 定义一个动物类
class Animal
{
public:
    // 虚函数，表示晚绑定（动态绑定）
    virtual void speak()
    {
        cout << "动物会说话" << endl;
    }
};

// 猫类
class Cat:public Animal
{
public:
    void speak()    // 也可这么写：visual void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

// 狗类
class Dog:public Animal
{
public:
    virtual void speak()    // 前面的 virtual 可写可不写
    {
        cout << "小狗在说话" << endl;
    }
};

// 满足 动态多态 的条件
// 1. 有继承关系
// 2. 子类重写父类的虚函数（子类重写的函数前的 virtual 可加可不加）

// 执行说话函数
// 这种写法，地址早绑定，编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数地址不能提前绑定，需要在运行阶段绑定，地址晚绑定(即在动物类的speak改为虚函数)
void doSpeak(Animal &animal)    // 父类的指针或者引用 指向子类对象
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}


int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}
