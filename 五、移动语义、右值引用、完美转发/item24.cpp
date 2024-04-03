#include <vector>
#include <iostream>

//模板通用引用，必须T&&+类型推导
template <typename T>
void func(T &&param)
{
    std::cout << "T&&" << std::endl;
}

//template <class T,class Allocator = allocator<T>>
//class vector{public push_back(T&& x);     //不是万能引用，因为已经定了}

//可变参数模板的万能引用， Args&&... + 类型推导
//template <typename T>
//class vector{public: template <typename...Args> void emplace_back(Args&&...args);}

//auto的万能引用， auto&&/auto&&... + 类型推导
//auto timeFuncInvocation = [](auto && func, auto && ...params)
//{
    //   start timer;
    //   std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
//}