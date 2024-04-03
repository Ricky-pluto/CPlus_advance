//当std::shared_ptr悬空时使用weak_ptr
//weak_ptr:监视者
#include <iostream>
#include <memory>
#include <unordered_map>
class Widget
{
    public:
    Widget(int id) : _id(id)
    {
        std::cout << "Widget(int id)" << std::endl;
    } 
    private:
    int _id{-1};
};

std::unique_ptr<const Widget> loadWidget(int id)
{
    //非常耗时
    std::unique_ptr<const Widget> uptr{new Widget(id)};
    return uptr;
}

std::shared_ptr<const Widget> fastLoadWidget(int id)
{
    //cache应该是个监视者，如果是shared_ptr,则会在外部删除不了原空间
    static std::unordered_map<int, std::weak_ptr<const Widget>> cache;
    auto objPtr = cache[id].lock();
    if(!objPtr)
    {
        objPtr = loadWidget(id);
        cache[id] = objPtr;
    }
    return objPtr;
}

int main()
{
    {
        auto spw = std::make_shared<int>(10);
        std::weak_ptr<int> wpw(spw);
        spw = nullptr;
        std::cout << "over" << std::endl;
    }
}




