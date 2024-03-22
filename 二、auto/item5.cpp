#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

template <typename It>
void dwim(It b, It e)
{
    while(b != e)
    {
        auto currValue = *b;
        std::cout << currValue << std::endl;
        b++;
    }
}

int main()
{
    int a = 10;
    // float &c = a;
    const float &b = a;

    std::vector<int> vec = {1, 2, 3, 4};
    dwim(vec.cbegin(), vec.cend());

    std::unordered_map<std::string, int> m{{"hello", 10}, {"world", 5}};
    for (const std::pair<std::string, int> &p : m)  //多了一次拷贝，将m的std::string拷贝为const std::string
    {
    }

    for (const auto &p : m)
    {

    }

    //z总结：多用auto
}