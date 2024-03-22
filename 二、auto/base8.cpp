#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <map>

int add(int i, int j)
{
    return i + j;
}

int modfunc(int i, int j, int m)
{
    m = 20;
    return i % j;
}



struct divide
{
    /* data */
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

using Fun = int(int, int);

bool isShorter(const std::string &a, int sz)
{
    return a.size() >= sz;
}

int main()
{
    std::vector<std::string> wordVec{"fun", "hello", "world"};

    int sz = 4;
    auto wc = find_if(wordVec.begin(), wordVec.end(), [sz](const std::string &a){return a.size() >= sz;});
    //闭包：带有上下文状态的函数。
    //实现形式：重载operator、lambda表达式捕获、std::bind

    using namespace std::placeholders;
    auto fun = std::bind(isShorter, _1, sz);
    auto wc2 = find_if(wordVec.begin(), wordVec.end(), fun);


    //可调用对象五种: 函数， 函数指针，lambda表达式， std::bind, 重载函数调用运算符的类。
    //std::function可以包含这五种。
    std::map<std::string, int (*)(int, int)> funcMap;

    int mm = 0;
    auto mod_  = [mm](int i, int j)
    { return i % j;};

    auto mod = [](int i, int j)
    { return i % j;};

    funcMap.insert({"+", add});
    //空捕获列表，lambda退化为函数指针
    funcMap.insert({"%", mod});
    // funcMap.insert({"%", mod_});

    auto modaaa = std::bind(modfunc, _1, _2, 20);
    std::map<std::string, std::function<int(int, int)>> funcMap2;
    funcMap2.insert({"+", add});
    funcMap2.insert({"%", mod_});
    funcMap2.insert({"%%", modaaa});
    return 0;

    

}