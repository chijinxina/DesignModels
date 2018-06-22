//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
using namespace std;

/*
 * 1. 定义产品接口
 */
//产品A接口
class AbstractProductA {
public:
    virtual void use()=0;
};
//产品B接口
class AbstractProductB {
public:
    virtual void eat()=0;
};

/*
 * 2. 定义抽象工厂
 */
class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA()=0;  //创建产品A 接口
    virtual AbstractProductB* CreateProductB()=0;  //创建产品B 接口
};

/*
 * 3. 实现产品接口
 */
//实现产品A
class ProductA1 : public AbstractProductA {
public:
    void use() override
    {
        cout<<"ProductA1 use()"<<endl;
    }
};
class ProductA2 :public AbstractProductA {
public:
    void use() override
    {
        cout<<"ProductA2 use()"<<endl;
    }
};
//实现产品B
class ProductB1 : public AbstractProductB {
public:
    void eat() override
    {
        cout<<"ProductB1 eat()"<<endl;
    }
};
class ProductB2 : public AbstractProductB {
public:
    void eat() override
    {
        cout<<"ProductB2 eat()"<<endl;
    }
};

/*
 * 4. 实现抽象工厂
 */
class ConcreateFactory1 : public AbstractFactory {
public:
    AbstractProductA*  CreateProductA() override
    {
        return new ProductA1;
    }

    AbstractProductB* CreateProductB() override
    {
        return new ProductB1;
    }
};

class ConcreateFactory2 : public AbstractFactory {
public:
    AbstractProductA*  CreateProductA() override
    {
        return new ProductA2;
    }

    AbstractProductB* CreateProductB() override
    {
        return new ProductB2;
    }
};

/*
 * 5. 使用抽象工厂
 */
int main()
{
    AbstractFactory* abstractFactory1 = new ConcreateFactory1();
    AbstractFactory* abstractFactory2 = new ConcreateFactory1();

    AbstractProductA* productA1 = abstractFactory1->CreateProductA();
    AbstractProductA* productA2 = abstractFactory2->CreateProductA();
    productA1->use();
    productA2->use();
    AbstractProductB* productB1 = abstractFactory1->CreateProductB();
    AbstractProductB* productB2 = abstractFactory1->CreateProductB();
    productB1->eat();
    productB2->eat();
    return 0;
}
