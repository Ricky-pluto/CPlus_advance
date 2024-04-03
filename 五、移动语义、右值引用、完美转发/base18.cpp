#include <iostream>
#include <vector>
class Test
{
    public:
    Test() {std::cout << "default ctor" << std::endl;}
    Test(int data1, int data2) {std::cout << "Test(int a, int b)" << std::endl;}
    Test(Test &&rhs) : _name(std::move(rhs._name))
    {
        std::cout << "move ctpr" << std::endl;
    }
    Test(const Test &rhs) : _name(rhs._name)
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
    std::vector<Test>tests;
    tests.reserve(10);
    // Test tt(10, 20);
    // tests.emplace_back(tt);
    // tests.push_back(tt);

    // tests.emplace_back(Test(20,50));
    // tests.push_back(Test(20,50));

    //emplace_back明显可变参数模版，一定是万能引用
    tests.emplace_back(50, 60);
    //push_back函数模版T与原vector相同，重载两次函数针对左值和右值
    tests.push_back({50, 60});


}