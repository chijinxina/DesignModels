//
// Created by chijinxin on 18-6-22.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 1. 创建接口
 */
//迭代器接口
template <typename Item>
class Iterator {
public:
    virtual ~Iterator(){cout<<"Destruct Class Iterator"<<endl;}

    virtual void First()=0;
    virtual void Next()=0;
    virtual bool isEnd()=0;
    virtual Item* CurItem()=0;
};

//container接口
template <typename Item>
class Container {
public:
    Container() = default;
    virtual ~Container(){}

    virtual int getSize()=0;
    virtual void pushItem(const Item &item)=0;
    virtual Item& operator[](int index)=0;
    virtual Iterator<Item> *getIterator()=0;
};
/*
 * 2. 创建实现Iterator的实体类
 */
template <typename Item>
class ConcreteIterator : public Iterator<Item> {
public:
    //构造函数
    ConcreteIterator(Container<Item>* container):container_(container),curIndex_(0)
    {}

    void First() override {
        curIndex_ = 0;
    }

    void Next() override {
        ++curIndex_;
    }

    bool isEnd() override {
        return curIndex_>=container_->getSize();
    }

    Item *CurItem() override {
        if(curIndex_<container_->getSize())
        {
            return &(*container_)[curIndex_];
        }
        return nullptr;
    }


private:
    Container<Item>* container_;
    int curIndex_;
};

/*
 * 3. 创建实现了 Container 接口的实体类
 */
template <typename Item>
class ConcreteContainer : public Container<Item> {
public:
    virtual ~ConcreteContainer()
    {
        if(iterator_)
        {
            delete(iterator_);
        }
    }

    int getSize() override {
        return data_.size();
    }

    void pushItem(const Item &item) override {
        data_.push_back(item);
    }

    Item &operator[](int index) override {
        return data_[index];
    }

    //获取迭代器
    Iterator<Item> *getIterator() override {
        if(iterator_)
        {
            return iterator_;
        }
        else
        {
            return iterator_ = new ConcreteIterator<Item>(this);
        }
    }


private:
    std::vector<Item> data_;
    Iterator<Item>* iterator_{nullptr};
};



/*
 * 验证迭代器工作
 */
int main()
{
    Container<int>* container = new ConcreteContainer<int>();
    container->pushItem(1);
    container->pushItem(2);
    container->pushItem(3);
    container->pushItem(4);
    container->pushItem(5);

    Iterator<int> * iterator = container->getIterator();
    for(iterator->First(); !iterator->isEnd(); iterator->Next())
    {
        cout<<*(iterator->CurItem())<<endl;
    }

    return 0;
}
