#include <iostream>
#include <functional>
#include <memory>
#include <string>
#include <functional>
#include <vector>

struct Test
{
    Test(){}
    Test(int data) : _data(data)
    {
        std::cout << "Test()" << std::endl;
    }
    Test(const Test &rhs) : _data(rhs._data) {std::cout << "Test(const Test& rhs)" << std::endl;}
    Test(Test &&rhs) : _data(rhs._data) {std::cout << "Test(Test &&rhs)" << std::endl;}
    int func(int a, int b)
    {
        std::cout << "a is:" << a << std::endl;
        std::cout << "b is:" << b << std::endl;
        return a - b;
    }

    private:
    int _data;
};

void fun1(Test &a)
{
}

void fun2(Test a)
{
}

void fun3(Test &&a)
{
}

int add(int a, int b)
{
    return a + b;
}

struct Widget
{
    /* data */
    int add(int a, int b)
    {
        return a + b;
    }
};


int main()
{
    auto add5 = std::bind(add, 5, std::placeholders::_1);
    int result = add5(10);
    Widget w;
    auto add10 = std::bind(&Widget::add, &w, 10, std::placeholders::_2);

    Test t(50);
    auto funBind1 = std::bind(fun1, t); //bind源码里有个decay，会发生拷贝
    auto funBind2 = std::bind(fun2, std::ref(t));
    auto funBind3 = std::bind(fun3, t);

    Test t1(50), t2(50), t3(50);
    auto funBind4 = std::bind(fun1, std::move(t1));
    auto funBind5 = std::bind(fun2, std::move(t2));
    auto funBind6 = std::bind(fun3, std::move(t3));

}