#include <iostream>
using namespace std;

// 对象的初始化和清理
// 1. 构造函数 进行初始化操作

class Person
{
private:
    /* data */
public:
    // 构造函数，没有返回值也不写void
    // 函数名称与类名相同
    // 构造函数可以有参数，因此可以发生发生重载
    // 程序在调用对象时候会自动调用构造函数，无须手动调用，而且只会调用一次
    Person();

    // 析构函数，没有返回值也不写void
    // 函数名称与类名相同，在名称前加上符号～
    // 析构函数不可以有参数，因此不可以发生重载
    // 程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次
    ~Person();
};

// 构造函数调用
Person::Person(/* args */)
{
    cout << "Person 构造函数的调用" << endl;
}
// 析构函数调用
Person::~Person()
{
    cout << "~Person 析构造函数的调用" << endl;
}

// 构造函数和析构函数是必须有的实现，如果自己不提供，编译器会提供一个空实现
void test01()
{
    Person p;   // 在栈上的数据，函数执行完后，会释放这个对象
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}