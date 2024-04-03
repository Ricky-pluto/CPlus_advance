//对于移动成本且总是被拷贝的可拷贝形参，考虑按值传递
#include <iostream>
#include <vector>

class Test
{
    public:
    Test(int data1)
    {

    }
    Test(const Test &rhs) { std::cout << "Test(const Test)" << std::endl;}
    Test(Test &&rhs) { std::cout << "Test(Test &&rhs)" << std::endl;}
};

//方法1、对左右值重载
class Widget1
{
    public:
    Widget1()
    {
        _tests.reserve(10);
    }
    void addTest(const Test &newTest)
    {
        _tests.push_back(newTest);
    }
    void addTest(Test &&newTest)
    {
        _tests.push_back(std::move(newTest));
    }
    private:
    std::vector<Test> _tests;
};

//方法2、万能引用
class Widget2
{
    public:
    Widget2()
    {
        _tests.reserve(10);
    }
    template <typename T>
    void addTest(T&& newTest)
    {
        _tests.push_back(std::forward<T>(newTest));
    }

    private:
    std::vector<Test> _tests;
};

//方法3、按值传递
class Widget3
{
    public:
    Widget3()
    {
        _tests.reserve(10);
    }
    void addTest(Test newTest)
    {
        _tests.push_back(std::move(newTest));
    }

    private:
    std::vector<Test> _tests;
};


int main()
{
    // Widget1 w1;
    // Widget2 w1;
    Widget3 w1;
    Test t1(10);
    w1.addTest(t1);
    w1.addTest(Test(20));
}