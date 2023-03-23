#ifndef _KKB_SHOP_H_
#define _KKB_SHOP_H_
#include <string>
#include <queue>

class kkbOrderInfo;
class kkbShop
{
private:
    std::queue<kkbOrderInfo*> _orders;
    const std::string _shopid;
    

public:
    kkbShop(const char* name);
    ~kkbShop();

    inline const std::string id(){return _shopid;}

public:
    virtual void applyOrder();
    virtual void onOrderFinish(kkbOrderInfo* order);


};






#endif