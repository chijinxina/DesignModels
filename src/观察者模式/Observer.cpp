//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
 * Observer
 * 观察者模式
 * 关键代码：在抽象类里有一个 ArrayList存放观察者们。
 */

/*
 * 创建Observer接口
 */
class Subject;
class Observer {
protected:
    Subject* subject_;  //被观察者

public:
    Observer(Subject* subject):subject_(subject){}
    virtual ~Observer(){}
    virtual void update()=0;
};

/*
 * 创建Subject类
 * 被观察者
 */
class Subject {
private:
    list<Observer*> observers_;  //观察者
    int state_;                  //状态

public:
    //获取状态
    int GetState()
    {
        return state_;
    }

    //设置状态
    void SetState(int state)
    {
        state_ = state;
        NotifyAllObservers();
    }

    //绑定观察者
    void Attach(Observer* observer)
    {
        observers_.push_back(observer);
    }

    //通知所有观察者
    void NotifyAllObservers()
    {
        for_each(observers_.begin(),observers_.end(),
                 [](Observer* x)
                 {
                     x->update();
                 });
    }
};

/*
 * 创建实体观察者类，实现Observer接口
 */
//观察者1
class BinaryObserver : public Observer {
public:
    BinaryObserver(Subject* subject):Observer(subject)
    {
        subject_->Attach(this);  //将该观察者绑定到被观察者上
    }
    void update() override {
        cout<<"Binary String:"<<subject_->GetState()<<endl;
    }
};
//观察者2
class OctalObserver : public Observer {
public:
    OctalObserver(Subject* subject):Observer(subject)
    {
        subject_->Attach(this); //将该观察者绑定到被观察者上
    }

public:
    void update() override {
        cout<<"Octal String:"<<subject_->GetState()<<endl;
    }
};
//观察者3
class HexaObserver : public Observer {
public:
    HexaObserver(Subject* subject):Observer(subject)
    {
        subject_->Attach(this); //将该观察者绑定到被观察者上
    }

    void update() override {
        cout<<"Hex String:"<<subject_->GetState()<<endl;
    }
};


/*
 * 使用 Subject 和实体观察者对象
 */
int main()
{
    //创建被观察者
    Subject* subject = new Subject();

    Observer* ob1 = new BinaryObserver(subject);
    Observer* ob2 = new OctalObserver(subject);
    Observer* ob3 = new HexaObserver(subject);

    subject->SetState(1);
    subject->SetState(10);

    return 0;
}
