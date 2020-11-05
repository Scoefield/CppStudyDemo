#include <iostream>
using namespace std;

class Base
{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son1:public Base
{
    public:
        void func()
        {
            m_A = 100;  // 父类中的公共权限成员，到了子类中依然是公共成员
            m_B = 200;  // 父类中的保护成员，到了子类中依然是保护成员
            // m_C = 10;// 父类中的私有成员，到了子类中是访问不到
        }
};

void test01()
{
    Son1 s;
    cout << s.m_A << endl;
    // s.m_B = 20; // 到了Son1中， m_B是保护成员，类外访问不到
}

class Son2:protected Base
{
    public:
        void func()
        {
            m_A = 100;
            m_B = 300; 
            // m_C = 10;// 父类中的私有成员，到了子类中是访问不到
        }
};

void test02()
{
    Son2 s2;
    // s2.m_A = 1000;  // 在Son2中， m_A变为类保护权限， 因此类外访问不到
}

// 私有继承类似，这里就不再写了

int main(int argc, char const *argv[])
{
    /* code */
    // test01();
    test02();

    return 0;
}
