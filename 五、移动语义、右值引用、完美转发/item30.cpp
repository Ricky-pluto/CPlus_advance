#include <iostream>
#include <vector>

// void f(const std::size_t &v){}

void f(int (*pf)(int)) {}
int processVal(int value) { return 0;}
int processVal(int value, int priority) { return 0;}


class Widget
{
    public:
    static const std::size_t MinVals = 28;
    void f(std::size_t value);
};


template <typename T>
T workonVal(T param) { return param; }

template <typename T>
void fwd(T &&param)
{
    f(std::forward<T>(param));
}

int main()
{
    // fwd(Widget::MinVals); //错误，因为MinVal只有声明
    // fwd({1,2,3}); //模版函数推到不了inlitializer_list;
    auto i1 = {1, 2, 3};
    // fwd(i1);
    // fwd(processVal);
    // fwd(workonVal);
    using ProcessFunType = int (*)(int);
    ProcessFunType processValPtr = processVal;
    fwd(processValPtr);
    fwd(static_cast<ProcessFunType>(workonVal));
    return 0;
}