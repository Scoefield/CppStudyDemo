#include <iostream>
using namespace std;

// 深浅拷贝操作

class Person
{
public:
    // 无参构造函数
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    // 有参构造函数
    Person(int a, int h)
    {
        m_Age = a;
        m_Height = new int(h);
        cout << "Person的有参构造函数调用" << endl;
    }
    // 析构造函数
    ~Person()
    {
        // 将堆区开辟的空间释放掉
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;    // 防止野指针出现
        }
        cout << "Person的析构造函数调用" << endl;
    }

    // 自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "Person拷贝造函数调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height;   // 编译器默认实现就是这行代码(浅拷贝)
        // 深拷贝操作
        m_Height = new int(*p.m_Height);
    }

    int m_Age;  // 年龄
    int *m_Height; // 身高
};

void test01()
{
    Person p1(18, 160);
    cout << "Person的年龄：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;

    Person p2(p1);  // 执行来浅拷贝操作（调用默认的拷贝函数）
    cout << "P2的年龄：" << p1.m_Age << "身高为：" << *p2.m_Height << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    test01();

    return 0;
}
