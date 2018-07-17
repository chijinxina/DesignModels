//
// Created by chijinxin on 18-7-17.
//
#include <iostream>
using namespace std;
/*
 * 代理模式
 * 例子： 假若你有一个工厂开始是生产手机的，但是它现在不想自己生产了，它把自己的东西交给了一家代工厂富士康去生产，那么便有了下面的代码去构建。
 * Subject抽象主体角色，抽象类或者接口，是一个普通的业务类型定义
 * RealSubject具体主体角色，也叫作被委托角色，被代理角色。业务逻辑的具体执行者
 * Proxy代理主体角色，委托类，代理类。
 */
//Subject接口 统一的抽象接口
class Subject{
public:
    virtual void Request() = 0;  //具体代理的任务接口
};

//Subject接口实现类
class ConcreteSubject : public Subject {
public:
    void Request() override {
        cout<<"ConcreteSubject"<<endl;
    }
};

//代理类
class Proxy : public Subject{
public:
    Proxy(Subject* subject)
    {
        this->subject_ = subject;
    }

    void Request() override {
        subject_->Request();    //代理类控制被代理类的访问
    }

private:
    Subject* subject_;    //代理类拿到被代理类的对象
};

int main()
{
    Subject* subject = new ConcreteSubject();
    Proxy* proxy = new Proxy(subject);
    proxy->Request();     //利用代理对象来间接访问ConcreteSubject对象
    return 0;
}
