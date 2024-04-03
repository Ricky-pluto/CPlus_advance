//模版元编程初探
//元(meta)含义：meta X = X about X；
// 模版元编程：使用模版编写程序的程序
// 模版元函数：编译期执行且输入输出可为数值。也可为类型

#include <iostream>
#include <vector>
#include <type_traits>

//输入是类型，输出也是类型
template <typename T>
struct Func1
{
    /* data */
    using type = T;
};

template <int a>
struct Func2
{
    /* data */
    int data[a];
};

// SFINAE.替换失败并非错误
// class Person
// {
//     public:
//     Person() = default;

//     //让他SIFNIA让他走下一个
//     template <typename T, typename T2 = typename Func1<T>::b_type>
//     Person(T &&n) : _name(std::forward<T>(n))
//     {
//         std::cout << "Person(T&&n)" << std::endl;
//     }

//     //升级：enable_if

//     Person(const Person &p)
//     {
//         std::cout << "Person(const Person &p)" << std::endl;
//     }

//     private:
//     std::string _name;
// };

namespace
{
    template <bool, typename _Tp = void>
    struct enable_if
    {
    };

    template <typename _Tp>
    struct enable_if<true, _Tp>
    {
        /* data */
        typedef _Tp type;
    };   
}

class Person
{
    public:
    Person() = default;

    template <typename T, typename T2 = typename std::enable_if<!std::is_integral<std::remove_reference_t<T>>::value>>
    explicit Person(T && n) : name(std::forward<T>(n)) {}

    // 升级：enable_if

    explicit Person(int idx)
    {
        std::cout << "Person(const Person &p)" << std::endl;
    }

    private:
    std::string _name;
};



int main()
{
    Func1<int>::type value = 10;
    // Func1<int>::type_b value1 = 10;

    Func2<1> f;
    Person p;
    Person p1(p);

}
