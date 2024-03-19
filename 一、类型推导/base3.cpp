#include <iostream>
#include <vector>
#include <string>
void fun(int a[])
{}

void fun(int (*ptr2)[5])//5不可忽略
{}

bool fun(int a, int b);//bool(int, int)的数据类型

bool (*funptr)(int a, int b);//bool(*)(int, int)


using int_name = int;
int_name ooo = 10;

using fun3Ptr = bool(*)(int, int);
using fun3xxx = bool(int, int);
// fun3Ptr fun3(int c) == fun3xxx* fun3(int c) == bool (*fun3(int c))(int, int);
bool(&funref)(int, int) = fun;


int main()
{
    int a = 10;
    int array[5] = {0, 0, 0, 0, 0};
    std::vector<int> aaaaa;
    int *ptr = array;
    int *ptr[5] = {&a, &a, &a, &a, &a};//数组5个int*型
    int(*ptr)[5] = &array;//ptr指向int[5];ptr的类型为int(*)[5]
    int(&ref)[5] = array;//ref的类型为int(&)[5]
    //没有 int &ptr[5]

    &"hello world";// const char [12] 常量区所以是左值
    char str[12] = "hellp world";
    const char *ptrrrr = "hello world";
    // char *ptrr = "hello world";//应该报错的

    



}