//优先使用std::make_shared
//processWidget(std::shared_ptr<Widget>(new Widget), computepriority());如果computeriority出现异常则会出现内存泄漏.
//一：可改为std::shared_ptr<Widget> spw(new Widget);   processWidget(std::move(spw), computepriority());
//二：改为processWidget(std::make_shared<Widget>(new Widget), computepriority());

//make_shared会一次性的将所需内存申请下来，包括control_block;
//问题：a、自定义删除器只能new。b、{}不能完美转发。 c、重载operator new后，不会调用。 d、T object和control block会一起申请。
#include <vector>
#include <memory>
#include <iostream>

int main()
{
    auto upv = std::make_unique<std::vector<int>>(10, 20);
    auto spv = std::make_shared<std::vector<int>>(10, 20);
    // auto spv_ = std::make_shared<std::vector<int>>({10, 20});  //{}不能完美转发
}