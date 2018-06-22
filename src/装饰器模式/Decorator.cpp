//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
using namespace std;
/*
 * Decorator
 * 装饰器模式
 */

/*
 * 创建一个接口
 */
class Shape {
public:
    virtual ~Shape(){}
    virtual void draw()=0;
};


/*
 * 实现接口的实体类
 */
class Circle : public Shape {
public:
    void draw() override {
        cout<<"Draw a Circle"<<endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout<<"Draw a Rectangle"<<endl;
    }
};


/*
 * 创建实现Shape接口的抽象装饰类
 */
class ShapeDecorator : public Shape {
public:
    explicit ShapeDecorator(Shape* shape):shape_(shape){}

    virtual void draw() override {
        shape_->draw();
    }

protected:
    Shape* shape_;
};

/*
 * 创建扩展了 ShapeDecorator 类的实体装饰类。
 */
class RedShapeDecorator : public ShapeDecorator {
public:
    explicit RedShapeDecorator(Shape* shape):ShapeDecorator(shape){}

    void draw() override {
        std::cout << "<red>" << std::endl;
        shape_->draw();
        std::cout << "<red/>" << std::endl;
    }
};

class GreeShapeDecorator : public ShapeDecorator {
public:
    explicit GreeShapeDecorator(Shape* shape):ShapeDecorator(shape){}

    void draw() override {
        std::cout << "<green>"<< std::endl;
        shape_->draw();
        std::cout << "<green/>" << std::endl;
    }
};


/*
 * 使用 RedShapeDecorator 和 GreenShapeDecorator来装饰 Shape 对象。
 */
int main()
{
    Shape* circle = new Circle();
    Shape* rectangle = new Rectangle();
    circle->draw();
    rectangle->draw();
    Shape* redDecorator = new RedShapeDecorator(circle);
    Shape* greenDecorator = new GreeShapeDecorator(circle);
    redDecorator->draw();
    greenDecorator->draw();
    return 0;
}
