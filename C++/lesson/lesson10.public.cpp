#include <iostream>

using namespace std;

class B{
public:
    virtual void f() const{
        cout << "B::f()\n";
    }
    virtual void g(int){
        cout << "B::g(int)\n";
    }
};

// class D : private B{
class D : public B{
public:
    virtual void f() const{
        cout << "D::f()\n";
    }
    virtual void g(bool){
        cout << "D::g(bool)\n";
    }
};

int main(){
    B* p = new B;
    p->f();
    p->g(0);
    delete p;
    p = new D();
    p->f();
    p->g(0);
    delete p;

    return 0;
}