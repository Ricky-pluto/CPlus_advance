#include <iostream>
#include <typeinfo>

class A
{
    public:
    A()
    {
        data1_ = new int();
        data2_ = new int();
    }
    virtual void vAfunc1() { std::cout << "A::vAfunc1()" << std::endl;}
    virtual void vAfunc2() { std::cout << "A::vAfunc2()" << std::endl;}

    void func1() {std::cout << "A::func1()" << std::endl;}
    void func2() {std::cout << "A::func2()" << std::endl;}

    virtual ~A()
    {
        std::cout << "A::~A" << std::endl;
        delete data1_;
        delete data2_;
    }

    private:
    int* data1_;
    int* data2_;
};

class B : public A
{
    public:
    B()
    {
        data3_ = new int();
    }

    virtual void vAfunc1() override{ std::cout << "B::vAfunc1()" << std::endl;}
    virtual void vBfunc1() { std::cout << "A::vBfunc1()" << std::endl;}
    virtual void vBfunc2() { std::cout << "A::vBfunc2()" << std::endl;}

    void func2() {std::cout << "B::func2()" << std::endl;}
    virtual ~B()
    {
        std::cout << "B::~B" << std::endl;
        delete data3_;
    }

    private:
    int *data3_;
};

int main()
{
    A a;
    a.vAfunc1();
    a.func1();

    B b;
    b.vAfunc1();
    b.func1();
    b.func2();

    A aa = b;
    aa.vAfunc1();  //不表现多态，强制转换后虚表变了。
    aa.func1();
    aa.func2();

    A *aaptr = &b;
    aaptr->vAfunc1();  //表现多态，虚表不变。
    aaptr->func1();
    aaptr->func2();

    A *aptr = new B();
    delete aptr;//如果A的析构函数不是虚函数。没有虚表析构时只析构A。
    //RTTI-------Run Time Type Identification
    std::cout << "======" << typeid(a).name() << std::endl;

    A qqq;
    B *ppp = dynamic_cast<B *>(&qqq);//不安全，子类指针不能指父类，会丢字节

    A *mm = dynamic_cast<A *>(&b);
    B *nn = dynamic_cast<B *>(mm);  //安全，根据tupeinfo保留了之前的字节数

    

}