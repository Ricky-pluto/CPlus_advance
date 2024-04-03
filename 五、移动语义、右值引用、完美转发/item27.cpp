//熟悉通用引用的替代方法
//1.使用传值，见item41
//2.使用tag dispatch
#include <iostream>
#include <vector>
#include <type_traits>
std::vector<std::string> names;

template <typename T>
void logAndAddImpl(T &&name, std::false_type type)
{
    names.emplace_back(std::forward<T>(name));
}

std::string nameFromIdx(int idx)
{
    return "name";
}

void logAndAddImpl(int idx, std::true_type type)
{
    names.emplace_back(nameFromIdx(idx));
}


template <typename T>
void logAndAdd(T &&name)
{
    logAndAddImpl(std::forward<T>(name),
                    std::is_integral<typename std::remove_reference<T>::type>());
}

//3、使用enable_if
//参考base19

int main()
{
    short a = 1;
    logAndAdd(a);
}
