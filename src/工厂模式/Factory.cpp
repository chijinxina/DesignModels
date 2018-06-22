//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <memory>
using namespace std;

/*
 * 1. 创建接口
 */
class Shape {
public:
    virtual ~Shape(){cout<<"Destruct Class Shape"<<endl;}
    virtual void draw()=0;
};

/*
 * 2. 创建实现接口的实体类
 */
class Circle : public Shape {
public:
    void draw() override
    {
        cout<<"draw a Circle"<<endl;
    }
};

class Square : public Shape {
public:
    void draw() override
    {
        cout<<"draw a Square"<<endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override
    {
        cout<<"draw a Rectangle"<<endl;
    }
};

/*
 * 3. 创建一个工厂，生成基于给定信息的实体类的对象
 */
class ShapeFactory {
public:
    std::shared_ptr<Shape> getShape(const std::string& shapeType)
    {
        if(shapeType=="Circle")
        {
            return std::make_shared<Circle>();
        }
        else if(shapeType=="Square")
        {
            return std::make_shared<Square>();
        }
        else if(shapeType=="Rectangle")
        {
            return std::make_shared<Rectangle>();
        }
        return nullptr;
    }
};


/*
 * 使用该工厂，通过传递类型信息来获取实体类的对象
 */
int main()
{
    ShapeFactory factory;
    auto shape1 = factory.getShape("Circle");
    shape1->draw();
    auto shape2 = factory.getShape("Square");
    shape2->draw();
    auto shape3 = factory.getShape("Rectangle");
    shape3->draw();
    return 0;
}
