#include <vector>
#include <functional>
#include <iostream>

//避免默认捕获，不安全
std::vector<std::function<bool(int)>> filters;

void addDivisorFilter()
{
    int divisor = 5;
    filters.emplace_back([&](int value){ std::cout <<value;});
    //divisor会over
}

class Widget
{
    private:
    int divisor = 0;
    public:
    void addFilter() 
    {
        filters.emplace_back([=](int value){std::cout << value;});    //"="实际上只捕获到this指针
    }
};

void addDivisorFilter2()
{
    static int divisor = 0;
    divisor ++;
    filters.emplace_back([=](int value){return value % divisor == 0;});
    //实际上不捕获，只是可以访问静态变量
}