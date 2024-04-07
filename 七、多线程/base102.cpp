#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <deque>
#include <condition_variable>

std::mutex mtx;
std::deque<int> q;

std::condition_variable cv;

//producer
void task1()
{
    int i = 0;
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        q.push_back(i);
        cv.notify_one();
        if(i < 99999999)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
}

// //consumer
// void task2()
// {
//     int data = 0;
//     while(true)
//     {
//         std::unique_lock<std::mutex> lock(mtx);

//         if(q.empty())
//         {
//             cv.wait(lock);
//         }

//         if(!q.empty())
//         {
//             data = q.front();
//             q.pop_front();
//             std::cout << "Get value from que: " << data << std::endl;
//         }
//     }
// }

// //consumer 2,会虚假唤醒
// void task3()
// {
//     int data = 0;
//     while(true)
//     {
//         std::unique_lock<std::mutex> lock(mtx);

//         if(q.empty())
//         {
//             cv.wait(lock);
//         }

//         if(!q.empty())
//         {
//             data = q.front();
//             q.pop_front();
//             std::cout << "Get value from que: " << data << std::endl;
//         }
//     }
// }

//consumer 3
void task4()
{
    int data = 0;
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);

        while(q.empty())
        {
            cv.wait(lock);
        }

        data = q.front();
        q.pop_front();
        std::cout << "Get value from que: " << data << std::endl;

    }
}

int main()
{
    std::thread t1(task1);
    // std::thread t2(task2);
    // std::thread t3(task3);
    std::thread t4(task4);
    t1.join();
    // t2.join();
    // t3.join();
    t4.join();
}