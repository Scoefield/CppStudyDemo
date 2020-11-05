#include <iostream>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = age;            // 方式一
        // this->age = age;   // 方式二  this指针指向被调用的成员函数所属对象
    }
    Person& PersonAddAge(Person &p)
    {
        this->m_Age += p.m_Age;     // 将传入对象的年龄和本身对象年龄想加 
        return *this;               // this指向本身对象的指针，而*this指向的就是对象本体（相对于解引用）
    }

int m_Age;  // 方式一使用
// int age; // 方式二使用
};

// 1.解决名称冲突
void test01()
{
    Person p1(18);
    cout << "p1 的年龄：" << p1.m_Age << endl;
}

// 2. 返回对象本身
void test02()
{
    Person p1(10);
    Person p2(13);

    // 链式编程思想
    p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
    cout << "相加后 p1 的年龄：" << p1.m_Age << endl;
}


int main(int argc, char const *argv[])
{
    /* code */
    // test01();
    test02();

    return 0;
}
