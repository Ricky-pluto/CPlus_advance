#include <iostream>

int main()
{
    const int a = 10;  //a不能修改
    int b = a;   //b拷贝为a

    const int *const p = new int(10);//前一个是底层const，后一个是顶层const
    // int *p1 = p;//顶层const可以忽略
    // int *const p2 = p;
    const int *p3 = p;
    //当执行对象拷贝操作时，常量的顶层const不受什么影响，而底层const必须一致
    // int *p4 = &a; //&a变成了底层const

    //引用不是对象，不满足上面原则
    // int &r4 = 20;   20不是对象,非常量引用不能等于常量
    const int &r1 = 20;   //常量引用在左侧，右侧可以接任何东西
    // int &r4 = a;//a是const，r4可以改引起矛盾

    int c = r1;// int c = a,即非常量可以等于常量引用


}