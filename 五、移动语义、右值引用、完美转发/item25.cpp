#include <iostream>
class Widget
{
    public:
    Widget() {std::cout << "default ctor" << std::endl;}
    Widget(Widget &&rhs) : _name(std::move(rhs._name))
    {
        std::cout << "move ctpr" << std::endl;
    }
    Widget(const Widget &rhs) : _name(rhs._name)
    {
        std::cout << "copy ctpr" << std::endl;
    }

    // template <typename T>
    // void setName(T &&newName)
    // {
    //     _name = std::forward<T>(newName);
    //     // _name = std::move<T>(newName);  //如果move会把传入左值杀死
    // }

    void setName(std::string &&newName)
    {
        std::cout << "move setName" << std::endl;
        _name = std::move(newName);
    }
    void setName(const std::string &newName)
    {
        std::cout << "copy setName" << std::endl;
        _name = newName;
    }
    private:
    std::string _name;
};


int main()
{
    std::string name = "hkl";
    Widget w;
    w.setName(name);
    w.setName(std::move(name));
    w.setName("Xiaoming");

}