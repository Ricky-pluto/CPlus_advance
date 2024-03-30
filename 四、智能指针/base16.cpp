#include <iostream>
#include <vector>
//一直重载operator new/delete非常不合理，std::allocator应运而生，专门做内存管理


class Test
{
    public:
    Test()
    {
        std::cout << "Test addr is " << this << std::endl;
    }
    Test(int a) : _a(a)
    {
        std::cout << "Test(int a) addr is " << this << std::endl;
    }
    Test(int a, int b)
    {
        std::cout << "Test(int a, int b) addr is " << this << std::endl;
    }

    ~Test()
    {
        std::cout << "~Test addr is " << this << std::endl;
    }

    private:
    int _a;
};

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int *a = new int(10);
        std::cout << a << std::endl;
    }

    int *a = new int[3]{1, 23, 34};
    std::cout << a << std::endl;
    std::cout << a + 1 << std::endl;
    std::cout << a + 2 << std::endl;
    delete a;  //正确
    // delete[] a;  //正确

    Test *t = new Test[3]{Test(1), Test(2), Test(3)};
    delete[] t;  //正确
    // delete t; //错误
    return 0;
}