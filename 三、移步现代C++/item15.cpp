#include <iostream>
#include <string>
#include <vector>
#include <array>

//const常量的不确定性
int get_value()
{
    return 1;
}

constexpr int get_value_c()
{
    return 1;
}

constexpr int abs_(int x)
{
    int mm = 10;
    mm = 80;
    return x>0? x : -x;
}

class A
{
    public:
    constexpr A() : x1(5) {}
    constexpr A(int i) : x1(i) {}
    constexpr int get() const
    {
        return x1;
    }

    ~A() = default;

    int x1;
};

int main()
{
    int e = 10;
    const int a = 10;
    const int b = 1+2;//看光标知道了是编译期常量
    const int c = e;
    const int d = get_value();
    constexpr int f = get_value_c();
    constexpr int g = abs_(a);

    //gcc支持动态开辟
    char array_a[a];
    char array_b[b];
    char array_c[c];
    char array_d[d];
    char array_e[e];

    std::array<int, a> array_aa{};
    std::array<int, b> array_bb{};
    // std::array<int, c> array_cc{};
    // std::array<int, d> array_dd{};

    //constexpr值：可以保证声明的常量是编译期常量。所有的constexpr都属于const 

    //constexpr函数（很神奇）
    //参数列表里不能也不需要声明为constexpr
    constexpr A a1(a);
    constexpr A a1(); //理解成了函数声明
    // constexpr A a2(e);
    constexpr A a2(a);
    //经过更新后，constexpr声明里的括号实现可以修改常量。


    
    


}