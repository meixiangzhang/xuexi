#include <iostream>

using namespace std;

namespace master{

template<class C>
class print{
public:
    template<class U>
    print(U u){
        cout << u << " ";
    }

    template<class T>
    print& operator()(T t){
        cout << t << " ";
        return *this;
    }

};

}

int main(){
    //模板类、模板函数
    master::print<void>(666)("123")(456)("kaikeba")(789)("\n");

    master::print<void>("123")(456)("kaikeba")(789)("\n");


    return 0;
}