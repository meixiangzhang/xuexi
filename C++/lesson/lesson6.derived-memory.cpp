#include <iostream>

using namespace std;

struct A{
    A(){
        cout << "A constructor" << endl;
    }
    ~A(){
        cout << "A destructor" << endl;
    }

    int a;
};
struct B : virtual public A{
    B(){
        cout << "B constructor" << endl;
    }
    ~B(){
        cout << "B destructor" << endl;
    }

    int b;
};
struct C : public B{
    C(){
        cout << "C constructor" << endl;
    }
    ~C(){
        cout << "C destructor" << endl;
    }

    int c;
};

//虚继承的情况下，虚基类的空间是放在类对象的最后面
//也即是实部先进行组合，最后对虚部进行整合

int main(){
    C c;
    cout << "address C = " << &c << endl;
    cout << "address C.a = " << &c.a << endl;
    cout << "address C.b = " << &c.b << endl;
    cout << "address C.c = " << &c.c << endl;

    A* pA = &c;
    B* pB = &c;
    cout << "pA = " << pA << endl;
    cout << "pB = " << pB << endl;

    return 0;
}