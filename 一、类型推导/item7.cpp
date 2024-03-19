#include <vector>
#include <string>
#include <array>
#include <iostream>
//C11聚合类，存在问题：初始化任务给了用户
struct people
{
    int age;
    std::string name;
    float height;
};

//C17聚合类。可以公有继承非虚
class MystringWithIndex : public std::string
{
    public:
        int index_ = 0;
};

struct A
{
    /* data */
    A()
    {
        std::cout << "A()" << std::endl;
    }
    A(int a)
    {
        std::cout << "A(int a)" << std::endl;
    }
    A(int a, int b)
    {
        std::cout << "A(int a, int b)" << std::endl;
    }

    A(const A &a)
    {
        std::cout << "A(const A& a)" <<std::endl;
    }
    //1、隐式缩窄转换  2、Initialize_list的构造总是优先匹配  
    A(std::initializer_list<int> a)
    {
        std::cout << "C(std::initializer_list<int> a)" <<std::endl;
        for(const int *item = a.begin(); item!= a.end(); ++item)
        {

        }
    }
};

void f(double value)
{
    //可以当作变量的创建，也可以当作函数的声明
    int i(int (value));
}

struct Timer
{

};

struct TimerKeeper
{
    /* data */
    TimerKeeper(Timer t){}
};

struct S
{
    int x;
    int y;
};



int main()
{
    // A a = 10;
    // A b(10);
    // A c = 10;
    // A d{10};
    // A e = {10};

    // A f = 10,5;
    // A g(10, 5);//作为函数返回值时，也会不停的拷贝成temp;
    A i = {10, 5};//完美解决问题
    // A j = {10, 5.};

    
    TimerKeeper timer_keeper(Timer());//又理解成了函数声明
    int a1[3]{1,2,3};
    int a2[3] = {1,2,3};
    std::array<int, 3> a3{1,2,3};
    std::array<int, 3> a4 = {1,2,3};
    S a5[3] = {{1,2},{3,4},{5,6}};
    S a6[3] = {1,2,3,4,5,6};//括号的省略

    std::array<S, 3>a7{{{1,2},{3,4},{5,6}}};

    std::vector<int> vec{1,2,3,4,5,6};

    A aaaaaaa{{}};
    A bbbbbbb({});

}

