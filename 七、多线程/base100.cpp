//创建线程
#include <iostream>
#include <thread>

void f(int) 
{
    while(true)
    {
        std::cout << "Hello world!\n";
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
}

int main()
{
    std::thread t{ f, 1};//已经开始执行

    std::cout << "thread id is " << t.get_id();

    while(true)
    {
        std::cout <<"Cat\n";
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
    t.join(); //等待子线程，阻塞
    // t.detach(); //将子线程和主线程分离，不会阻塞

    // std::thread t2;
    // std::thread t3{std::move(t)};//此时t3拥有所有权
    // t3.join();
}