#include <iostream>

struct A
{
    /* data */
    int a{20};
    void funcA() {std::cout << "A::FUNA" << std::endl;}
};

struct B
{
    /* data */
    int b{};
    void funcB() {std::cout << "B::FUNB" << std::endl;}
};

struct CA : public A
{
    /* data */
    int c{25};
    void funcCA()
    {
        std::cout << "c is: " << std::endl;
        std::cout << "CA::funcCA" << std::endl;
    }
};

struct Base
{
    /* data */
    virtual void func()
    {
        std::cout << "Base::func()" << std::endl;
    }
};

struct Derived : public Base
{
    /* data */
    virtual void func() override
    {
        std::cout << "Derived::func()" << std::endl;
    }
};

const std::string &shorterString(const std::string &s1,
                                const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

std::string &shorterString(std::string &s1,
                        std::string &s2)
{
    auto &r = shorterString(const_cast<const std::string &>(s1),
                            const_cast<const std::string &>(s2));

    return const_cast<std::string &>(r);
}







int main()
{
    float f = 10.f;
    int i = static_cast<int>(f);

    // static_cast,任意类型指针转换可以用void*作媒介
    A a;
    void *vap = static_cast<void *>(&a);
    int *ip = static_cast<int *>(vap);
    std::cout << "ip is :" << ip << std::endl;

    CA ca;
    A a_ = static_cast<A>(ca); //上行ok
    a_.funcA();
    // CA ca_ = static_cast<CA>(a); //下行报错

    CA *ca_ = static_cast<CA *>(&a);
    ca_->funcCA();//下行不安全

    CA &car_ = static_cast<CA &>(a);
    car_.funcCA();//下行不安全
    Base base;
    Derived derived;
    //dynamic_cast 根据type_Info运行时判断是否安全，不安全返回空指针。
    Base *_baseptr_d = dynamic_cast<Base *>(&derived); //上行ok
    _baseptr_d->func();
    Derived *_derivedptr_d = dynamic_cast<Derived *>(&base);//下行不安全，返回空

    //const_cast  去掉底层const
    const char *pc = "hello world";
    char *p = const_cast<char *>(pc);
    p[2] = 'a'; // 段错误

    //const_cast一般只用于函数重载。参考shorterString，很优雅

    //reinterpret_cast
    int *i_ = reinterpret_cast<int *>(i);
    int64_t cpi = reinterpret_cast<int64_t>(pc);
    //无需void*作媒介



    
}