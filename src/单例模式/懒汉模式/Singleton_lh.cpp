//
// Created by chijinxin on 18-6-21.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
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

private:
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
