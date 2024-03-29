#include <iostream>
#include <vector>

template <typename C, typename V>
void findAndInsert(C &container, const V &targetVal, const V &insertVal)
{
    using std::cbegin;
    using std::cend;

    auto it = std::find(cbegin(container),
                        cend(container),
                        targetVal);
    container.insert(it, insertVal);
}


int main()
{
    // std::vector<int> avec = {1,2,3,4,5};

    // std::vector<int>::iterator it =
    //     std::find(avec.begin(), avec.end(), 2);
    // avec.insert(it, 32);

    std::vector<int> avec = {1,2,3,4,5};

    std::vector<int>::const_iterator cit =
        std::find(avec.cbegin(), avec.cend(), 2);
    avec.insert(cit, 32);//此时cit已经指向新内存的地址了，故可以为const
}