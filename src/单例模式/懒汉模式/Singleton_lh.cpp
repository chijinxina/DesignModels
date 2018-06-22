//
// Created by chijinxin on 18-6-21.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

/*
 * Singleton
 * 懒汉模式：单例只在第一次使用时初始化一次
 *
 * 问题：
 * (1) 线程不安全  (多个线程同时getInstance，同时判断m_data是否为空，导致多次初始化实例)
 * (2) 析构函数没有执行(无法解决)
 */

class Singleton{
public:
    /*
     * 双重检查锁定模式(DCLP)
     * 问题:因为c++编译器在编译过程中会对代码进行优化，
     * 所以实际的代码执行顺序可能被打乱，另外因为CPU有一级二级缓存(cache),
     * CPU的计算结果并不是及时更新到内存的,所以在多线程环境，
     * 不同线程间共享内存数据存在可见性问题，从而导致使用DCLP也存在风险。
     */
    static Singleton* getInstance()
    {
        if(m_data == nullptr)  //第一次判断m_data是否为空，线程不安全，可能多个线程同时判空
        {
            std::lock_guard<std::mutex> lock(mu);
            if(m_data == nullptr) //第二次判空，加互斥锁，线程安全，保证只有一个线程来初始化Singleton
            {
                m_data = new Singleton();
            }
            return m_data;
        }
        else
        {
            return m_data;
        }
    }

    /*
     * 借助（内存栅栏技术 memory fence）来解决双重检查锁定模式的风险
     * 利用C++11提供的atomic_thread_fence实现内存栅栏memory fence
     * 在c++11中，可以获取(acquire/consume)和释放(release)内存栅栏
     * 使用c++11中的atomic类型来包装m_instance指针，这使得对m_instance的操作是一个原子操作。
     */


private:
    std::atomic<Singleton*> Singleton::m_instance;

    static Singleton* m_data;   //类内声明一个指向Singleton的静态指针，由getInstance在第一次调用时，初始化该指针

    static std::mutex mu;              //互斥量，保障getInstance线程安全

    Singleton(){cout<<"Construct Class Singleton!!!"<<endl;}
    ~Singleton(){}
};
Singleton* Singleton::m_data = nullptr;  //静态成员类外定义
std::mutex Singleton::mu;


void task()
{
    Singleton* a = Singleton::getInstance();
    while(1)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

int main()
{
    vector<std::shared_ptr<std::thread>> threadPool;
    for(int i=0;i<100;i++)
    {
        threadPool.push_back(std::make_shared<std::thread>(&task));
    }
    while(1)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
