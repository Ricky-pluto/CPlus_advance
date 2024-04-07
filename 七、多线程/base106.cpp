 //1.队列已满，生产者停止生产产品-》生产者wait条件变量
 //2.队列为空，消费者无商品可取-》消费者wait条件变量
 //3.队列不满不空，正常
 #include <iostream>
 #include <condition_variable>
 #include <deque>
 #include <mutex>
 #include <vector>

template<typename T>
class ProducerConsumer
{
    public:
    ProducerConsumer(): m_QueueMaxSize(20), m_Producer(2), m_Consumer(2), m_RunningStatus(true)
    {
        initialize();
    }
    ProducerConsumer(int queueMaxSize, int producernum, int consumernum): m_QueueMaxSize(queueMaxSize), m_Producer(producernum), m_Consumer(consumernum), m_RunningStatus(true)
    {
        initialize();
    }
    ~ProducerConsumer()
    {
        m_RunningStatus = false;
        m_QueNotFullCV.notify_all();
        m_QueNotEmptyCV.notify_all();

        for(auto& thread : m_Producer)
        {
            if(thread.joinable())
            {
                thread.join();
            }
        }
        for(auto& thread : m_Consumer)
        {
            if(thread.joinable())
            {
                thread.join();
            }
        }
    }

    private:
    std::deque<T> m_que;
    int m_QueueMaxSize;
    std::condition_variable m_QueNotFullCV;
    std::condition_variable m_QueNotEmptyCV;

    std::vector<std::thread> m_Producer;
    std::vector<std::thread> m_Consumer;

    std::mutex m_Mutex;
    std::atomic<bool> m_RunningStatus;

    void initialize()
    {
        for(size_t i = 0; i < m_Producer.size(); i++)
        {
            m_Producer[i] = std::thread(&ProducerConsumer::producer, this);
        }

        for(size_t i = 0; i < m_Consumer.size(); i++)
        {
            m_Consumer[i] = std::thread(&ProducerConsumer::consumer, this);
        }
    }

    bool isFull()
    {
        if(m_que.size() >= m_QueueMaxSize)
        {
            return true;
        }
        return false;
    }

    void producer()
    {
        while(m_RunningStatus)
        {
            std::unique_lock<std::mutex> locker(m_Mutex);
            if(isFull())
            {
                std::cout << "Queue is full!wait for m_QueNotFullCV \n";
                m_QueNotFullCV.wait(locker);
            }

            //队列不满
            if(!isFull())
            {
                T value = 3;
                m_que.push_front(value);
                m_QueNotEmptyCV.notify_one();
            }
        }
    }

    void consumer()
    {
        while(m_RunningStatus)
        {
            std::unique_lock<std::mutex> locker(m_Mutex);
            if(m_que.empty())
            {
                std::cout << "Queue is empty!wait for m_QueNotEmptyCV \n";
                m_QueNotEmptyCV.wait(locker);
            }

            //队列不满
            if(!m_que.empty())
            {
                T value;
                value = m_que.at(0);
                m_que.pop_front();
                value++;
                std::cout << "result: " << value << "\n";
                m_QueNotFullCV.notify_one();
            }
        }
    }
};

int main()
{
    ProducerConsumer<int> ProducerConsumer(100, 6, 6);

    while(true)
    {

    }
}