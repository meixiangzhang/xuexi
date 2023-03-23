#include <iostream>

using namespace std;

class A{
public:
    // void test() = 0;//普通方法不可以=0
    virtual void print() = 0;//纯虚方法不允许类实例化
};

class B : public A{
public:
    // void test(){

    // }
    // void print(){
    //     cout << "B::print" << endl;
    // }
};
class C : public B{
public:
    void print(){
        cout << "C::print" << endl;
    }
};

int main(){
    // A* p = new B();
    // p->test();
    // A* p = new A();
    A* p = new C();
    p->print();

    return 0;
}