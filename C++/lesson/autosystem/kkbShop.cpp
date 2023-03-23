#include "kkbShop.h"
#include "kkbFactory.h"

kkbShop::kkbShop(const char* name) : _shopid(name)
{
    kkbFactory::instance()->registerShop(this);
}

kkbShop::~kkbShop()
{
}

void kkbShop::applyOrder(){
    kkbOrderInfo* order = kkbOrderInfo::create(
        _shopid,
        "BMW",
        "740",
        8.0f,
        4,
        20,
        0xff0000ff
    );
    this->_orders.push(order);
    kkbFactory::instance()->addOrder(order);
}

void kkbShop::onOrderFinish(kkbOrderInfo* order){
    
}