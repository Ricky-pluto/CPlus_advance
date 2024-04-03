//lambda表达式来捕获闭包，C14之后
#include <iostream>
#include <memory>
int main()
{
    auto pw = std::make_unique<int>();
    auto func = [pw = std::move(pw)]{ *pw = 1; };
}

//C14之前，std::bind