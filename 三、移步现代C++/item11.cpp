#include <iostream>
#include <string>
#include <vector>

struct B;

struct A
{
    A(int data) : _data(data){};
    A(const A &a) = delete;
    A &operator=(const A &) = delete;

    private:
    friend B;
    int _data;
};

struct B
{
    B()
    {
        A a(10);
    }
};

bool islucky(int a)
{
    return a == 7;
}

bool islucky(char) = delete;

template <typename T>
void processPointer(T *ptr)
{}

//模板特化
template <>
void processPointer<void>(void *ptr) = delete;

int main()
{
    A a(10);
    B b;
    islucky(32);
}
