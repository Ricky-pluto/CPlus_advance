//对于独占资源使用std::unique_ptr
//默认情况下unique_ptr大小＝原始， 他不允许拷贝，只允许移动。 
//可作为工厂函数的返回类型
#include <memory>
#include <iostream>

class Test
{
    public:
    Test(int a) : _data(a) { std::cout << "Test(int a)" << std::endl;}
    ~Test() {std::cout << "~Test" << std::endl; }
    private:
    int _data;
};

class Investment
{
    public:
    virtual ~Investment() {}
};

class Stock : public Investment
{
    public:
    Stock(int a) { std::cout << "Stock(int a)" << std::endl;}
    ~Stock() override { std::cout << "~Stock()" << std::endl;}
};

class Bond : public Investment
{
    public:
    Bond(int a, int b) { std::cout << "Bond(int a, int b)" << std::endl;}
    ~Bond() override { std::cout << "~Bond()" << std::endl;}
};

class RealEstate : public Investment
{
    public:
    RealEstate(int a, int b, int c) { std::cout << "RealEstate(int a, int b, int c)" << std::endl;}
    ~RealEstate() override { std::cout << "~RealEstate()" << std::endl;}
};


//ptr传不出去
template <typename... Ts>
Investment *makeInvestment_test(Ts &&...params)
{
    Investment *ptr;
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        Stock stock(std::forward<Ts>(params)...);
        ptr = &stock;
    }
    if constexpr (numArgs == 2)
    {
        Bond bond(std::forward<Ts>(params)...);
        ptr = &bond;
    }
    if constexpr (numArgs == 3)
    {
        RealEstate realestate(std::forward<Ts>(params)...);
        ptr = &realestate;
    }
}

//ptr要记得删
template <typename... Ts>
Investment *makeInvestment_test2(Ts &&...params)
{
    Investment *ptr;
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        Stock *stock = new Stock(std::forward<Ts>(params)...);
        ptr = &stock;
    }
    if constexpr (numArgs == 2)
    {
        Bond *bond = new Bond(std::forward<Ts>(params)...);
        ptr = &bond;
    }
    if constexpr (numArgs == 3)
    {
        RealEstate *realestate = new RealEstate(std::forward<Ts>(params)...);
        ptr = &realestate;
    }
}

template <typename... Ts>
std::unique_ptr<Investment>
makeInvestment(Ts &&...params)
{
    std::unique_ptr<Investment> uptr(nullptr);
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        uptr.reset(new Stock(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 2)
    {
        uptr.reset(new Bond(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 3)
    {
        uptr.reset(new RealEstate(std::forward<Ts>(params)...));
    }
}

template <typename... Ts>
auto makeInvestment2(Ts &&...params)
{
    // 自定义删除器
    auto delInvmt2 = [](Investment *pInvestment)
    {
        std::cout <<"delete" << std::endl;
        delete pInvestment;
    };
    std::unique_ptr<Investment, decltype(delInvmt2)> uptr(nullptr, delInvmt2);
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        uptr.reset(new Stock(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 2)
    {
        uptr.reset(new Bond(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 3)
    {
        uptr.reset(new RealEstate(std::forward<Ts>(params)...));
    }
}  
