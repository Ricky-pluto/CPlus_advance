#include <iostream>
#include <memory>

void f(int)
{
    std::cout << "f(int)" << std::endl;
}

void f(bool)
{
    std::cout << "f(bool)" << std::endl;
}

void f(void *)
{
    std::cout << "f(void *)" << std::endl;
}

int f1(std::shared_ptr<int> spi)
{
    return 5;
}

double f2(std::unique_ptr<int> upi)
{
    return 5.;
}

bool f3(int *pi)
{
    return true;
}

template <typename FuncType, typename PtrType>
decltype(auto) func(FuncType f, PtrType ptr)
{
    return f(ptr);
}


int main()
{
    int *aa = 0;
    int *bb = NULL;
    int *cc = nullptr;

    auto a = 0;
    auto b = NULL;    //b是long类型
    auto c = nullptr;

    f(0);
    // f(NULL);//重载的NULL都可以转换
    f(nullptr);


    auto result3 = func(f3, nullptr);
    // auto result3 = func(f3, 0); //错误,0赋给了变量，不能转为int *
    // auto result2 = func(f2, NULL);  //同理报错


}