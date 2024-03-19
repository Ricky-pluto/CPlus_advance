#include <iostream>
#include <memory>
#include <type_traits>
namespace
{
    template <typename T> //C11
    typename std::remove_reference<T>::type &&move(T &&param)
    {
        using ReturnType = typename std::remove_reference<T>::type &&;
        return static_cast<ReturnType>(param);
    }

    template <typename T> //C14
    decltype(auto) move2(T &&param)
    {
        using ReturnType = std::remove_reference_t<T> &&;
        return static_cast<ReturnType>(param);
    }
}

struct A
{
    /* data */
    A(int value) : b(value) {std::cout << "create";}
    A(const A &value)
    {
        std::cout << "copy";
        b = value.b;
    }
    A(A &&value)
    {
        std::cout << "move";
        b = value.b;
        value.b = 0;
    }
    
    int b;
};


template <typename T>
typename std::remove_reference<T>::type &&mymove(T &&param)
{
    using ReturnType = typename std::remove_reference<T>::type &&;
    return static_cast<ReturnType>(param);
}

void process(const A &lvalArg)
{
    std::cout << "deal lVal" << std::endl;
}

void process(A &&rvalArg)
{
    std::cout << "deal rVal" << std::endl;
}

//std::forward--根据T有条件的将右值转左值
template <typename T>
void logAndProcess(T &&param)
{
    //param传进来后不知道是左值还是右值了
    // process(param);
    process(std::forward<T>(param));

}


int main()
{
    int mmm = 10;
    int &&nnn = mymove(mmm);
}