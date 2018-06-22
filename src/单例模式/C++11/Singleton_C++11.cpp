//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/*
 * Singleton
 * 用C++11 call_once实现Singleton
 */

class Singleton{
public:
    static Singleton* m_instance;
    static Singleton* getInstance();

private:

    Singleton(){cout<<"Construct Class Singleton!!!"<<endl;}
    ~Singleton(){cout<<"Destruct Class Singleton!!!"<<endl;}
};

Singleton* Singleton::m_instance;  //类外定义静态变量

Singleton* Singleton::getInstance()
{
    static std::once_flag oc;//用于call_once的局部静态变量
    std::call_once(oc,
                   [&]()
                   {
                       m_instance = new Singleton();
                   });
    return m_instance;
}

int main()
{
    Singleton::getInstance();
    while(1)
    {
        this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0;
}
