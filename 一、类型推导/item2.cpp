#include <iostream>
//万能引用，auto &&

template <typename T>
void f(T param)
{

}

template <typename T>
void g(std::initializer_list<T> param)
{

}

auto createInitList()
{
    //auto作为返回值，按模板的来，推不成initializer_list;
    // return {1,2,3};
    return std::initializer_list<int> {1,2,3};
}

int main()
{
    auto x1 = 27;
    auto x2(27);
    auto x3{27};
    auto x4 = {27}; //initializer_list<int>

    // auto x5{10, 27};//错误
    auto x5 = {10, 27};
    // f({1,2,3});//T推不出
    g({1,2,3});



    return 0;
}