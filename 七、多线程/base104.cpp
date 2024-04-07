//promiss and future
#include <future>
#include <thread>
#include <condition_variable>
#include <iostream>

// std::mutex mtx;
// std::condition_variable cv;

// void task(int a, int b, int& ret)
// {
//     int ret_a = a * a;
//     int ret_b = b * b;
//     std::unique_lock<std::mutex> lock(mtx);
//     ret = ret_a + ret_b;
//     cv.notify_one();  //已经计算完了
// }

void task(int a, int b, std::promise<int>& ret)
{
    int ret_a = a * a;
    int ret_b = b * b;
    ret.set_value(ret_a + ret_b);
}

void task2(int a, std::future<int>& b, std::promise<int>& ret)
{
    int ret_a = a * a;
    int ret_b = b.get() * 2;
    ret.set_value(ret_a + ret_b);
}

int main()
{
    int ret = 0;

    std::promise<int> p_ret;
    std::future<int> f_ret = p_ret.get_future();
    // std::thread t(task,1,2,std::ref(p_ret));

    //do_something

    // std::cout << "return value is " << f_ret.get(); //get只能一次

    std::promise<int> p_in;
    std::future<int> f_in = p_in.get_future();

    //多个线程可以创建shared_future.可以多次get
    std::shared_future<int> s_f = f_in.share();


    std::thread t2(task2, 1, std::ref(f_in), std::ref(p_ret));

    //do something
    //acquire f_in;
    p_in.set_value(2); 
    std::cout << "return value is" << f_ret.get();




    // t.join();
    t2.join();


    // std::thread t(task,1,2,std::ref(ret));
    // //do something else
    // std::unique_lock<std::mutex> lock(mtx);
    // cv.wait(lock);
    // std::cout << "return value is " << ret;
    // t.join();
}