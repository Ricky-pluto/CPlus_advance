#include <iostream>
#include <string>
#include <vector>
class A
{
    public:
    A(int param) : mm(param) {}
    A(const A &a)
    {
        std::cout << "A (const A&a)" << std::endl;
        mm = a.mm;
    }

    A(A &&a)
    {
        std::cout << "A (&&a)" << std::endl;
        mm = a.mm;
        a.mm = 0;
    }

    A &operator=(const A &a)
    {
        std::cout << "A &operator=(const A &a)" << std::endl;
        mm = a.mm;
        return *this;
    }

    A &operator=(A &&a)
    {
        std::cout << "A &operator=(A &&a)" << std::endl;
        mm = a.mm;
        a.mm = 0;
        return *this;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }



    private:
    int mm;
};

int main()
{
    A a{1};
    A aa{2};
    A b = a;
    b = aa;
    //编译器会自动帮我们构建默认的两种构造两种赋值
    
    //1.析构  2.拷构 3.拷赋 4.移构 5.移赋
    //五法则：声明一个五构造之一的一个，都应该同时声明其他四个。
    //兼容C++98：声明1/可以自动生成2、3.
    //声明1、2、3.不会生成4、5.
    //声明4、5。不会生成2、3、4、5.
    //析构函数一定会有
    //注意！！！：写了析构忘了写移动会导致std::move实际上还是拷贝。
    //可以写成A(A &&a) = default;
}