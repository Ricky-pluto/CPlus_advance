//对于共享资源使用std::shared_ptr
#include <memory>
#include <vector>
#include <iostream>

//std::shared_ptr有16个字节8个字节指向T，。后8个字节维护堆区域的control block（reference count，week count，other data）
//reference count必须动态分配  
//control block的生成时机：1.使用std::make_shared.  2.通过unique_ptr构建shared_ptr.  3.向shared_ptr构造传入一个裸指针
//多个share_ptr指向同一个目标时，应该也同时指向同一个control_block，否则会多次释放

class Test
{
    public:
    Test()
    {
        std::cout << "Test addr is " << this << std::endl;
    }
    Test(int data) : _data(data)
    {
        std::cout << "Test(int a) addr is " << this << std::endl;
    }
    Test(int data, int data2)
    {
        std::cout << "Test(int a, int b) addr is " << this << std::endl;
    }
    Test(const Test &t)
    {
        std::cout << "Test(const Test &t) addr is " << this << std::endl;
    }

    ~Test()
    {
        std::cout << "~Test addr is " << this << std::endl;
    }

    private:
    int _data;
};

int main()
{
    auto pt = new Test(1, 2);
    std::shared_ptr<Test> sp1(pt);
    // std::shared_ptr<Test> sp2(pt);    //这样会两次析构

    //修正
    std::shared_ptr<Test> sp2(new Test(1, 2));
    std::shared_ptr<Test> sp3(sp2); 

    return 0;
}