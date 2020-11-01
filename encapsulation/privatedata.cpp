#include <iostream>

using namespace std;

/*
    成员属性设置为私有：
        优点一：将所有成员属性设置为私有，可以自己控制读写权限。
        优点二：对于写权限，我们可以检测数据的有效性。
*/

//定义一个人类
class Person
{
public:
    // 设置姓名
    void setName(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string getName()
    {
        return m_Name;
    }

    // 获取年龄
    int getAge()
    {
        return m_Age;
    }

    // 设置情人，只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    // 姓名，设置可读可写
    string m_Name;
    // 年龄，设置只读
    int m_Age;
    // 情人，设置只写
    string m_Lover;
};

int main(int argc, char const *argv[])
{
    Person p;
    p.setName("jack");
    cout << "姓名为：" << p.getName() << endl;
    cout << "年龄为：" << p.getAge() << endl;

    p.setLover("Mike");
    // cout << "情人是：" << p.getLover() << endl;  // 是不可以访问

    return 0;
}
