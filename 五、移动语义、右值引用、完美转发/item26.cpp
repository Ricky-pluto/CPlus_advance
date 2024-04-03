#include <iostream>
#include <string>
#include <vector>

//避免万能引用的重载
std::vector<std::string> names;

template <typename T>
void logAndAdd(T &&name)
{
    names.emplace_back(std::forward<T>(name));
}

std::string nameFromIdx(int idx)
{
    return "name";
}

void logAndAdd(int idx)
{
    names.emplace_back(nameFromIdx(idx));
}

int main()
{
    short a = 1;
    // logAndAdd(a);//本来想转换成int走下面的函数，但是变成万能引用走了第一个报错
}
