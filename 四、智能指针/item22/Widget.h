#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Widget
{
    public:
    Widget();
    //如果提前default,会使得pImpl未实现先定义析构导致报错
    // ~Widget() = default;
    ~Widget();
    // Widget(Widget &&rhs) = default;
    //同理:unique_ptr也会出现这个问题
    Widget(Widget &&rhs);
    // Widget &operator=(Widget &&rhs) = default;
    Widget &operator=(Widget &&rhs);

    private:
    struct  Impl;
    std::unique_ptr<Impl> pImpl;

};