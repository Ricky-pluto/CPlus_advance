//堆栈内存分配流程上内存泄漏
#include <iostream>
int func(int a)
{
    int b = 10;
    a = b;
    return a;
}

int main()
{
    int c = 30;
    int d = func(c);
    return 0;
}

void func(int *a)
{
    *a = 10;
}

int main()
{
    int c = 30;
    func(&c);
    return 0;
}

void func(int *a)
{
    a = new int(10);
}

int main()
{
    int c = 30;
    func(&c);
    return 0;
}

void func(int **a)
{
    *a = new int(10);
}

int main()
{
    int *c = nullptr;
    func(&c);
    return 0;
}