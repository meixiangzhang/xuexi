#include "kkbFactory.h"
#include "kkbShop.h"
#include <iostream>


kkbFactory* kkbFactory::_instance = nullptr;
kkbFactory* kkbFactory::instance(){
    if(_instance == nullptr){
        _instance = new kkbFactory();
    }
    return _instance;
}

kkbFactory::kkbFactory() : _thread(nullptr)
{
    this->startWork();
}

kkbFactory::~kkbFactory()
{
    // this->stopWork();
}
//启动工作线程
void kkbFactory::startWork(){
    if(_thread){
        this->stopWork();
    }
    _thread = new std::thread(&kkbFactory::workThread, this);
    
}

//停止工作线程
void kkbFactory::stopWork(){
    if(_thread){
        _thread->join();
        delete _thread;
        _thread = nullptr;
    }
}
//工作线程函数
void kkbFactory::workThread(){
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        _mtx.lock();
        this->dealOrder();
        _mtx.unlock();
    }
}

void kkbFactory::registerShop(kkbShop* shop){
    _shops[shop->id()] = shop;
}

void kkbFactory::addOrder(kkbOrderInfo* order){
    _mtx.lock();
    _pendingOrders.push(order);
    _orders[order] = false;
    _mtx.unlock();
}

void kkbFactory::dealOrder(){
    if(!_pendingOrders.empty()){
        auto order = _pendingOrders.front();
        //交给流水线处理
        std::cout << "取队首订单交给流水线处理，当前队列大小 = " << _pendingOrders.size() << std::endl;

        //出队
        _pendingOrders.pop();

    }else{
        std::cout << "订单队列为空" << std::endl;
    }
}