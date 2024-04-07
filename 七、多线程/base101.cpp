#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
//两个线程访问公共资源
std::mutex mtx1;
std::mutex mtx2;
int globalVariable = 0;

// std::atomic<int> globalVariable = 0;   //不需要任何操作就是线程安全

void task1()
{
    for (int i = 0;i < 10000000; i++)
    {
        //有lock_guard不需要lock和unlockq且可解决死锁1.
        // std::lock_guard<std::mutex> lock1(mtx1);
        // std::lock_guard<std::mutex> lock2(mtx2);

        // std::unique_lock<std::mutex> lock3(mtx1);
        // lock3.unlock();
        //unique_lock比lock_guard更灵活
        mtx1.lock();
        //与task2产生死锁
        mtx2.lock();

        // std::lock(mtx1, mtx2); //解决死锁2
        globalVariable++;
        globalVariable--;
        //CallFunc() ;抛出异常
        //if return情况
        //死锁，上锁不解锁
        mtx1.unlock();
        mtx2.unlock();
    }
}

void task2()
{
    for (int i = 0;i < 10000000; i++)
    {
        mtx2.lock();
        mtx1.lock();
        globalVariable++;
        globalVariable--;
        //CallFunc() ;抛出异常
        //if return情况
        //死锁，上锁不解锁
        mtx2.unlock();
        mtx1.unlock();
    }
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    std::cout << "current value is " << globalVariable;
}