//单任务队列，线程池
//提交的任务：普通函数，lambda函数，仿函数（重载（）运算符的类或结构体），类的成员函数，std::function/std::packaged_task
//返回值不同，参数列表也不同

#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>
#include <iostream>
#include <future>
#include <deque>

class SimpleThreadPool
{
    public:
    SimpleThreadPool(const SimpleThreadPool&) = delete;
    SimpleThreadPool& operator=(const SimpleThreadPool&) = delete;
    SimpleThreadPool(SimpleThreadPool&&) = delete;
    SimpleThreadPool& operator=(SimpleThreadPool&&) = delete;
    SimpleThreadPool() : m_Threads(6), m_RunningStatus(true)
    {
        initialize();
    }

    SimpleThreadPool(int threadnum) : m_Threads(threadnum), m_RunningStatus(true)
    {
        initialize();
    }

    template<typename Func, typename... Args>
    auto submitTask(Func&& func, Args... args)
    {
        using returnType = std::invoke_result_t<Func, Args...>;
        std::function<returnType()> taskwrapper = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
        auto taskwrapper2 = std::make_shared<std::packaged_task<returnType()>>(taskwrapper); //packaged_task可以使用future;
        TaskType wrapperFunction = [taskwrapper2]()
        {
            (*taskwrapper2)();//没有返回值也没有参数列表
        };

        m_TaskQueue.push_front(wrapperFunction);
        m_CV.notify_one();

        return taskwrapper2->get_future();
    }

    ~SimpleThreadPool()
    {
        m_RunningStatus = false;
        m_CV.notify_all();
        for(auto& thread : m_Threads)
        {
            if(thread.joinable())
            {
                thread.join();
            }
        }
    }
    private:
    using TaskType = std::function<void()>;
    std::deque<TaskType> m_TaskQueue;
    std::vector<std::thread> m_Threads;

    std::condition_variable m_CV;
    std::mutex m_Mutex;
    std::atomic<bool> m_RunningStatus;

    void initialize()
    {
        int h = m_Threads.size();
        for(int i = 0; i < m_Threads.size(); i++)
        {
            int a = 1;
            auto worker = [this, i]()
            {
                while(m_RunningStatus)
                {
                    TaskType task;
                    bool isSuccess = false;
                    {
                        std::unique_lock<std::mutex> locker(m_Mutex);
                        if(this->m_TaskQueue.empty())
                        {
                            this->m_CV.wait(locker);
                        }
                        task = m_TaskQueue.at(0);
                        m_TaskQueue.pop_front();
                        isSuccess = true;   
                        
                    }
                    if(isSuccess)
                    {
                        std::cout << "Start running task in worker:[ID]" << i << "\n";
                        task();
                        std::cout << "End running task in worker:[ID]" << i << "\n";
                    }
                }
            };
            m_Threads[i] = std::thread(worker);
        }
    }
};

int very_time_consuming_task(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return a + b;
}

int main()
{
    SimpleThreadPool SimpleThreadPool(12);

    int taskNum = 30;
    std::vector<std::future<int>> result(30);

    std::cout << "Start to submit tasks..\n";
    for(size_t i = 0; i < taskNum; i++)
    {
        result[i] = SimpleThreadPool.submitTask(very_time_consuming_task, i, i+1);
    }

    std::cout << "End submit tasks...\n";
    std::cout << "Main thread do something else...\n";
    //do something
    std::this_thread::sleep_for(std::chrono::seconds(10));
    //
    std::cout << "Main thread task finished...\n";

    std::cout <<"Try getting threadpool task result...\n";

    for(size_t i = 0; i < taskNum; i++)
    {
        std::cout << "result[" << i << "]" << result[i].get();
    }    
    std::cout << "End of getting result\n";
    
}