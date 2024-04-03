//假定移动操作不存在，成本高，未被使用
// 1/std::array的移动操作
#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::vector<int> vm1;
    vm1.push_back(2);
    auto vm2 = std::move(vm1);

    std::array<int, 5>arr;
    auto arr2 = std::move(arr);

    std::cout << (sizeof(vm1)) << std::endl;
    std::cout << (sizeof(arr)) << std::endl;
    
    //小字符串会sso，存在栈区。
}