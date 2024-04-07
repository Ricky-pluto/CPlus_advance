#include <future>
#include <condition_variable>
#include <iostream>
#include <functional>

int task(int a, int b)
{
    int ret_a = a * a;
    int ret_b = b * 2;
    return ret_a + ret_b;
}

int main()
{
    // std::future<int> fu = std::async(std::launch::async, task, 1, 2); //会创建新的线程,还有延迟调用参数
    // std::cout << "return value is " << fu.get();

    std::packaged_task<int(int, int)> t(task);
    t(1, 2);
    std::cout << "return value is " << t.get_future().get();

    std::packaged_task<int()> t2(std::bind(task,1,2));
    t2();
}