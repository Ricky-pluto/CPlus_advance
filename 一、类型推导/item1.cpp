#include <iostream>
// void fun(int a){}

//template<typename T>
//void f(ParamType param);
//通用引用:传入左值ParamType为左值引用，传入右值ParamType为右值引用。
//引用折叠，int&与int&&可折叠为int&
//T &&param万能引用，而const T &&param只能传右值


void fun(const int a){}//和上面等价

template <typename T>
void f(const T &&param)
{
    std::cout << param << std::endl;
}
void func(int, int){}
int func2(int) {return 10;}
int (*func2ptr)(int) = func2;//也可以&func2
int (*const func2ptr)(int) = func2;

using F = int(int);

int main()
{
    //函数的底层const感觉只能通过别名
    const F *aaa = func2;//底层
    F *const bbb = func2;//顶层

    //函数引用的底层const会被忽略
    const F &ccc = func2;

    int a = 10;
    int *aptr = &a;
    int &aref = a;
    int &&arref = std::move(a);

    const int ca = 20;
    const int *captr = &ca;
    const int &caref = ca;//顶层const和等号右边的引用都忽略。和int ca没区别。
    const int &&careff = std::move(ca);

    int *const acotr = &a;
    const int *const accotr = &a;
    10;

    int array[2] = {0, 1};
    "hello world";
    //数组退化为指针，const变成了底层const
    const char aaa[12] = "hello world";
    int(*arrayptr)[2] = &array;
    int(&arrayref)[2] = array;

    func;
    void(*funcptr)(int, int) = func;





    


}