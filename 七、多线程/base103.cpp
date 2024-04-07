#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <deque>
#include <condition_variable>

#include <semaphore>

//C20才能用
std::counting_semaphore<2> csem(0);

// using std::binary_semaphore = std::counting_semaphore<1>;

std::binary_semaphore bsem(0);

//release == condition_var notify
//acquire == condition_var wait 

void task()
{
    std::cout << "ready to recv signal: acquire\n";
    bsem.acquire();

    std::cout << "acquire end\n";

}

int main()
{
    std::thread t(task);
    std::cout << "ready to signal: release\n";
    bsem.release();
    std::cout << "signal end\n";
    t.join();
}