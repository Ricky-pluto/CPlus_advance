#include <iostream>


int fun(int x)
{
    std::cout << "fun" << std::endl;
    return x;
}

void func(int, int){}

template <typename Container, typename Index>
decltype(auto) testFun_right(Container &c, Index i)
{
    return c[i];
}

template <typename Container, typename Index>
decltype(auto) testFun_better(Container &&c, Index i)
{
    return std::forward<Container>(c)[i]; //虽然完美转发，但是[i]使返回变成左值
}



int main()
{
    //decltype变量所有信息会保留，数组、函数不退化
    int a = 10;
    int *aptr = &a;
    // decltype(*aptr) b;
    // decltype((a)) b;   //加括号保留了表达式属性。


    int &aref = a;
    int &&arref = std::move(a);

    const int ca = 20;
    const int *captr = &ca;

    const int &caref = ca;
    const int &&carref = std::move(ca);
    // decltype(carref) bb; //bb保留了所有信息

    int *const acptr = &a;
    const int *const cacptr = &a;
    // decltype(*cacptr) bb;

    10;
    decltype(10) bbb;

    int value = 20;
    decltype(fun(value)) value4;    //不会运行fun

    //某些情况下模板函数的返回值是无法提前得到的
    //C11,  auto ..... -> decltype
    //C14,  一个auto会按模板的方法推，可能吞引用。所以用decltype(auto)
    
    




}
