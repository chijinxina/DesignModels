//
// Created by chijinxin on 18-7-17.
//
#include <iostream>
using namespace std;
/*
 * 对象适配器
 * 1. 以PS2转USB转化器（适配器）为例
 */
//PS2接口
class PS2{
public:
    virtual ~PS2(){}
    virtual void isPS2() = 0;
};
//USB接口
class USB{
public:
    virtual void idUSB() = 0 ;
};
//USB实现
class USBer : public USB {
public:
    void idUSB() override {
        cout<<"This is a USB"<<endl;
    }
};

//适配器
class Adapter : public PS2{
private:
    USB* usb;

public:
    Adapter(USB* usb)
    {
        this->usb = usb;
    }

    void isPS2() override {
        usb->idUSB();
    }
};

/*
 * 例2 对象适配器模式
 * 角色：Target Adaptee Adapter
 * 客户端需要调用Request方法，而Adaptee类中没有该方法，为了使客户端能够使用Adaptee类
 * 需要提供一个包装（Wrapper）类Adapter，这个包装类包装了一个Adaptee的实例，从而将客户端
 * 与Adaptee衔接了起来。由于Adapter与Adaptee是委派关系
 */
//Target接口
class Target{
public:
    virtual void Request()=0;
};

//Adaptee类
class Adaptee{
public:
    void SpecificRequest()
    {
        cout<<"Called SpecificRequest()"<<endl;
    }
};

//Adapter类
class Adapter2 : public Target {
private:
    Adaptee* adaptee_;
public:
    Adapter2(Adaptee* a)
    {
        this->adaptee_ = a;
    }

    void Request() override {
        adaptee_->SpecificRequest();
    }
};


int main()
{
    USB* usb = new USBer();
    PS2* p = new Adapter(usb);
    p->isPS2();

    Adaptee* aa = new Adaptee();
    Target *t = new Adapter2(aa);
    t->Request();
    return 0;
}
