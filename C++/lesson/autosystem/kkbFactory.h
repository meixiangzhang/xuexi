#ifndef _KKB_FACTORY_H_
#define _KKB_FACTORY_H_
#include <string>
#include <queue>
#include <map>
#include <thread>
#include <mutex>

struct kkbOrderInfo{
    std::string shopid;//id
    std::string brand;//品牌
    std::string serial;//型号
    float engine;//引擎大小
    int seat;//座位数
    int wheel;//轮子尺寸
    long color;//颜色0xFFFFFFFF

    static kkbOrderInfo* create(std::string shopid, std::string brand, std::string serial,
        float engine, int seat, int wheel, long color){
        kkbOrderInfo* pInfo = new kkbOrderInfo();
        pInfo->shopid = shopid;
        pInfo->brand = brand;
        pInfo->serial = serial;
        pInfo->engine = engine;
        pInfo->seat = seat;
        pInfo->wheel = wheel;
        pInfo->color = color;
        return pInfo;    
    }
};

class kkbShop;
class kkbFactory
{
private:
    static kkbFactory* _instance;

    //Shop
    std::map<std::string, kkbShop*> _shops;
    //待处理订单
    std::queue<kkbOrderInfo*> _pendingOrders;
    //订单状态队列
    std::map<kkbOrderInfo*, bool> _orders;

    //多线程编程使用
    std::thread* _thread;
    std::mutex _mtx;

protected:
    kkbFactory();
    ~kkbFactory();

public:
    static kkbFactory* instance();

    //启动工作线程
    void startWork();
    //停止工作线程
    void stopWork();
    //工作线程函数
    void workThread();

public://Shop
    void registerShop(kkbShop* shop);
    void addOrder(kkbOrderInfo* order);

public://Builder
    void dealOrder();
    

};

#endif