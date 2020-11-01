#include <iostream>
using namespace std;

class Ctest1
{
    int m_A;    // 默认的权限为私有
};

struct Ctest2
{
    int m_A;    // 默认的权限为公有
};

int main() {
    // struct 和 class 的区别
    // struct 默认的权限为公共
    // class 默认的的权限为私有
    Ctest1 c1;
    // c1.m_A = 100;   // 编译会报错
    
    Ctest2 c2;
    c2.m_A = 100;
    
	cout  << "m_A:" << c2.m_A << endl;
	return 0;
}