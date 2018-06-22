//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * Visitor
 * 访问者模式
 * 在数据基础类中有一个方法接受访问者，将自身引用传入访问者
 */
class Computer;
class Mouse;
class Monitor;
class Keyboard;
/*
 * 定义访问者visistor访问者接口
 */
class ComputerPartVisitor {
public:
    virtual ~ComputerPartVisitor() = default;
    virtual void visit(Computer* computer) = 0;
    virtual void visit(Mouse* mouse) = 0;
    virtual void visit(Monitor* monitor) = 0;
    virtual void visit(Keyboard* keyboard) = 0;
};


/*
 * 定义一个表示元素的接口
 */
class ComputerPart {
protected:
    string name_;

public:
    explicit ComputerPart(const string &name):name_(std::move(name)){}
    virtual ~ComputerPart() = default;

    string getName()
    {
        return this->name_;
    }
    //接受访问者
    virtual void accept(ComputerPartVisitor* visitor) = 0;
};


/*
 * 创建实现了ComputerPart接口的实体类
 */
class Mouse : public ComputerPart {
public:
    explicit Mouse(const string &name):ComputerPart(name){}

    void accept(ComputerPartVisitor *visitor) override {
        visitor->visit(this);
    }
};

class Monitor : public ComputerPart {
public:
    explicit Monitor(const string &name):ComputerPart(name){}

    void accept(ComputerPartVisitor *visitor) override {
        visitor->visit(this);
    }
};

class Keyboard : public ComputerPart {
public:
    explicit Keyboard(const string &name):ComputerPart(name){}

    void accept(ComputerPartVisitor *visitor) override {
        visitor->visit(this);
    }
};

class Computer : public ComputerPart {
private:
    vector<ComputerPart*> computerParts_;

public:
    explicit Computer(const string &name):ComputerPart(name)
    {
        computerParts_.push_back(new Mouse("Mouse"));
        computerParts_.push_back(new Monitor("Monitor"));
        computerParts_.push_back(new Keyboard("Keyboard"));
    }

    ~Computer()
    {
        for_each(computerParts_.begin(),computerParts_.end(),
                 [](ComputerPart* x)
                 {
                     delete(x);
                 });
    }

    void accept(ComputerPartVisitor *visitor) override {
        for_each(computerParts_.begin(),computerParts_.end(),
                 [&visitor](ComputerPart* x)
                 {
                     x->accept(visitor);
                 });
        visitor->visit(this);
    }
};



/*
 * 创建实现访问者接口的实体类
 */
class ComputerPartDisplayVisitor : public ComputerPartVisitor {
public:
    void visit(Computer *computer) override {
        cout<<"display :"<<computer->getName()<<endl;
    }

    void visit(Mouse *mouse) override {
        cout<<"display :"<<mouse->getName()<<endl;
    }

    void visit(Monitor *monitor) override {
        cout<<"display :"<<monitor->getName()<<endl;
    }

    void visit(Keyboard *keyboard) override {
        cout<<"display :"<<keyboard->getName()<<endl;
    }
};

//另外定义一种访问者
class ComputerPartOutputVisitor : public ComputerPartVisitor {
public:
    void visit(Computer *computer) override {
        cout<<"output :"<<computer->getName()<<endl;
    }

    void visit(Mouse *mouse) override {
        cout<<"output :"<<mouse->getName()<<endl;
    }

    void visit(Monitor *monitor) override {
        cout<<"output :"<<monitor->getName()<<endl;
    }

    void visit(Keyboard *keyboard) override {
        cout<<"output :"<<keyboard->getName()<<endl;
    }
};

/*
 * 使用 ComputerPartDisplayVisitor 和 ComputerPartOutputVisitor 来访问 Computer 的组成部分。
 */
int main()
{
    ComputerPartVisitor* displayVisitor = new ComputerPartDisplayVisitor();
    ComputerPartVisitor* outputVisitor  = new ComputerPartOutputVisitor();

    Computer* computer = new Computer("computer");
    computer->accept(displayVisitor);
    computer->accept(outputVisitor);
    return 0;
}
