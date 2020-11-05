#include <iostream>
using namespace std;

// 常函数
class Person
{
public:
    // this 指针本质 是指针常量：指针的指向是不可以修改的
    // 相当于 const Person * const this;
    // 在成员函数后加const，修饰的this指向的值也不可以修改
    void showPerson() const
    {
        // this->m_A = 100;
        // this = NULL;    // this指针不可修改指针的指向
        this->m_B = 100;
    }
    void func()
    {
        m_A = 320;
    }

    int m_A;
    mutable int m_B;    // 特殊变量，即使在常函数中，也可以修改这个值
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
void test02()
{
    const Person p; // 在对象前加const，变为常对象
    // p.showPerson();
    // p.m_A = 100;
    p.m_B = 200;    // m_B是特殊值，在常对象下也可以修改

    // 常对象只能调用常函数
    p.showPerson();
    // p.func();    // 常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
