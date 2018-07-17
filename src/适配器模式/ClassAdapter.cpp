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

int main()
{
    PS2* p = new Adapter();
    p->isPS2();
    return 0;
}
