#include <iostream>

using namespace std;

// 静态成员函数
// 所以对象共享同一个函数
// 静态成员函数只能访问静态成员变量
class Person
{
public:
    // 静态成员函数
    static void func()
    {
        m_A = 120;  // 静态成员函数可以访问 静态成员变量
        // m_B = 200;  // 静态成员函数只能访问静态成员变量（无法区分到底是哪个对象的m_B）
        cout << "static void func 调用 " << endl;
    }

    static int m_A;  // 静态成员变量
    int m_B;        // 非静态成员变量

    // 静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout << "private func2" << endl;
    }
};
// 类里面的静态成员变量初始化
int Person::m_A = 100;

void test01()
{
    // 方式一：通过对象调用
    Person p;
    p.func();
    // 方式二：通过类名来调用
    Person::func();

    Person p2;
    // p2.func2():  // 访问不了私有成员函数
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
