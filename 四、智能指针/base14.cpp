#include <iostream>
#include <vector>
#include <string>

class Test
{
    //完全掌控：重写所有new和delete
    public:
    Test() { std::cout << "Test() addr is: " << this << std::endl;}
    Test(int a) : _a(a)
    {
        std::cout << "Test(int a) addr is: " << this << std::endl;
    }
    Test(int a, int b)
    {
        std::cout << "Test(int a, int b ) addr is: " << this << std::endl;
    }
    ~Test() { std::cout <<"~Test() addr is " << this << std::endl;}

    void *operator new(size_t size)
    {
        std::cout << "operator new(size_t size)" << std::endl;
        return malloc(size);
    }

    void operator delete(void *ptr)
    {
        std::cout << "operator delete(void *ptr)" << std::endl;
        free(ptr);
    }
    private:
    int _a;
};

int main()
{
    void* p1 = malloc(sizeof(Test) * 10);
    free(p1);

    //new相当于malloc(operator new)+类型转换+构造函数
    //delete相当于先析构然后free(operator delete).
    Test *p3 = new Test();
    delete p3;
}