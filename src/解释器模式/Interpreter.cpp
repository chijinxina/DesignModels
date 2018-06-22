//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <map>

using namespace std;

/*
 * Interpreter
 * 解释器模式
 */
/*
 * 创建上下文context
 */
class Context {
private:
    map<string, int> valueMap_;

public:
    int getValue(const string& key)
    {
        return valueMap_[key];
    }

    void addValue(const string& key, int value)
    {
        valueMap_.insert(make_pair(key,value));
    }
};

/*
 * 创建抽象表达式接口
 */
class AbstractExpression {
public:
    virtual ~AbstractExpression(){}
    virtual int interpreter(Context &context)=0;
};

/*
 * 创建两种非终结表达式
 */
class AddNontermialExpression : public AbstractExpression {
private:
    AbstractExpression* left_;
    AbstractExpression* right_;

public:
    AddNontermialExpression(AbstractExpression* left, AbstractExpression* right)
            :left_(left),right_(right)
    {}

    int interpreter(Context &context) override {
        return left_->interpreter(context) + right_->interpreter(context);
    }

};

class SubNontermialExpression : public AbstractExpression {
private:
    AbstractExpression* left_;
    AbstractExpression* right_;

public:
    SubNontermialExpression(AbstractExpression* left, AbstractExpression* right)
            :left_(left),right_(right)
    {}

    int interpreter(Context &context) override {
        return left_->interpreter(context) - right_->interpreter(context);
    }
};

/*
 * 创建终结表达式
 */
class TerminalExpression : public AbstractExpression {
private:
    int i_; //终结符不能再切割

public:
    TerminalExpression(int i):i_(i){}

    int interpreter(Context &context) override {
        return i_;
    }
};

int main()
{
    Context context;
    context.addValue("a",1);
    context.addValue("b",2);
    context.addValue("c",3);
    AbstractExpression* sub_left = new TerminalExpression(context.getValue("a"));
    AbstractExpression* sub_right= new TerminalExpression(context.getValue("b"));
    AbstractExpression* subvalue = new SubNontermialExpression(sub_left,sub_right);
    cout<<"subvalue = "<<subvalue->interpreter(context)<<endl;
    AbstractExpression* add_right= new TerminalExpression(context.getValue("c"));
    AbstractExpression* addvalue = new AddNontermialExpression(subvalue,add_right);
    cout<<"addvalue = "<<addvalue->interpreter(context)<<endl;
    return 0;
}
