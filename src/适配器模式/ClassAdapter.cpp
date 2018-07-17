//
// Created by chijinxin on 18-7-17.
//
#include <iostream>
using namespace std;
/*
 * 类适配器
 * 以 PS2 转 USB 转接器（适配器）为例
 */

//PS2接口
class PS2{
public:
    virtual void isPS2()=0;
};

//USB接口
class USB{
public:
    virtual void isUSB()=0;
};
//USB实现类
class USBer : public USB
{
public:
    void isUSB() override {
        cout<<"This is a USB!"<<endl;
    }
};

//适配器
class Adapter : public USBer, public PS2    //继承USBer 实现PS2接口
{
    void isPS2() override
    {
       isUSB();
    }
};


/*
 * 例子2
 * 角色：target、Adaptee、Adapter
 */
//目标接口类，客户需要的接口
class Target{
public:
    Target(){}
    virtual ~Target(){}

    virtual void Request()   //定义标准接口
    {
        cout<<"Target::Request()"<<endl;
    }
};

//需要适配的类
class Adaptee{
public:
    Adaptee(){}
    ~Adaptee(){}

    void SpecificRequest()
    {
        cout<<"Adaptee::SpecificRequest()"<<endl;
    }
};

//类模式，适配器类，通过public继承获得接口继承的效果，通过priviate继承获得实现继承的效果
class Adapter2 : public Target, private Adaptee
{
public:
    Adapter2(){}
    ~Adapter2(){}
    virtual void Request()   //实现target顶一下的Request接口
    {
        cout<<"Adapter2::Request()"<<endl;
        this->SpecificRequest();
        cout<<"-------------------"<<endl;
    }
};

int main()
{
    PS2* p = new Adapter();
    p->isPS2();

    //类模式Adapter
    Target* pTarget = new Adapter2();
    pTarget->Request();
    return 0;
}
