#include <iostream>
#include "kkbFactory.h"
#include "kkbShop.h"

using namespace std;

int main(){
    kkbShop* shop = new kkbShop("BMW-Shop-0001");
    kkbFactory::instance()->startWork();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        shop->applyOrder();
    }
    

    return 0;
}