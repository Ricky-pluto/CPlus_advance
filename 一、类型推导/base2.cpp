#include <iostream>
#include <string.h>
#include <string>

class BigMemoryPool
{
    public:
        static const int PoolSize = 4096;
        BigMemoryPool() : pool_(new char[PoolSize]){}
        ~BigMemoryPool()
        {
            if(pool_ != nullptr)
            {
                delete[] pool_;
            }
        }
        BigMemoryPool(BigMemoryPool &&other)
        {
            std::cout << "move" << std::endl;
            pool_ = other.pool_;
            other.pool_ = nullptr;
        }

        BigMemoryPool(const BigMemoryPool &other) : pool_(new char[PoolSize])
        {
            std::cout << "copy" << std::endl;
            memcpy(pool_, other.pool_, PoolSize);
        }
        
        private:
            char *pool_;
};


BigMemoryPool getPool()
{
    BigMemoryPool memoryPool;
    return memoryPool;
}

BigMemoryPool getPool(const BigMemoryPool aa)
{
    return aa;
}

int gx = 10;
int get_gx()
{
    return gx;
}

int get_x()
{
    int x = 20;
    return x;
}

int main()
{
    int x = 10;
    // int &y = 20;
    int &&y = 30;
    // &get_x();    右值
    // &get_gx();   右值
    // int *p1 = &x++; //右值，里面实现有个临时对象
    int *p2 = &++x;
    auto p3 = &"hello world";
    int &&a = get_x();
    BigMemoryPool bbb = getPool();
    BigMemoryPool ccc = std::move(bbb);//std::move只是把bbb转为了将亡值（右值）
}