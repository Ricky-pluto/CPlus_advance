#include <string>
#include <vector>
#include <memory>
#include <iostream>
//类型萃取器 std::remove_const_t<T> 可以将const T转为T
#include <type_traits>

//SubType既可能是成员变量，也可能是类型。
struct test1
{
    static int SubType;
};

struct test2
{
    typedef int SubType;
};

template <typename T>
class MyClass
{
    public:
        void foo()
        {
            //加上typename避免歧义
            typename T::SubType *ptr;
        }
};

template <class T>
using myVector = std::vector<T>;

template <typename T>
struct myVector2
{
    typedef std::vector<T> type;
};
