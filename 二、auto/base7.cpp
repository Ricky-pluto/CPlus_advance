#include <iostream>
#include <string>
#include <memory>

int a = 0;

//auto SizeComp = [sz] (const string& a){return a.size() > sz}实际上等价于：
class SizeComp
{
    public:
    SizeComp(size_t n) : sz(n){}
    bool operator()(const std::string &s) const { return s.size() > sz;}  //后一个const禁止修改类里的东西

    private:
    size_t &sz; //类里私有允许声明一个引用，但必须写入初始化列表。
};

class A
{
    public:
    void print() { std::cout << "Class A" << std::endl;}
    void test()
    {
        auto foo = [this]
        {
            print();
            x = 5;
        };
        foo();
    }

    private:
    int x;
};

int main()
{
    size_t sz = 10, ss = 50;
    //捕获了哪个，size里就包括哪个.
    auto SizeCompLambda = [&sz, &ss](const std::string &a)
    {
        return a.size() >= sz;
    };
    auto size = sizeof(SizeCompLambda);
    std::cout << "size is:" << size << std::endl;

    int b = 0;
    static int c = 0;

    //[captures] (params) specifiers exception -> ret {body}
    //exception : noexcept表示是否抛异常
    //specifiers : 可选限定符，默认是const. 加mutable即可修改
    //(params)可选参数列表。自从C14后可以使用auto
    //[captures]可捕获非静态的局部变量,可按值和引用和组合。
    //捕获发生在定义时，而不是使用时（理解本质是构造类）。引用的时候可以绑定值改变
    //[*this]捕获this指向的副本。

    

    auto fun1 = [b, &sz]
    {
        std::cout << "b is : " << b << std::endl;
        a = 10;//a,c不捕获仍然可使用 
        c = 12;
    };

    auto func_test = [sz]() mutable
    {   
        sz = 10;
        std::cout << "sz is : " << sz << std::endl;
    };

    sz = 50;
    func_test();

    //初始化列表不能自动推导
    auto fun2 = [](auto mm) -> int
    {
        mm = 20;
        return mm;
    };

    //广义捕获,区别作用域，所以可传右值
    //make_unique不可拷贝
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y)->int
    {
        return x + y + v1 + (*v2);
    };


}