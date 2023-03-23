#include <iostream>

using namespace std;
class A{
public:
    void run(){
        cout << "run A this = " << this << endl;
    }
    int a;
};
class B : virtual public A{//会在B对象的头部生成一个虚基表指针，占8字节

};
class C : virtual public A{//会在C对象的头部生成一个虚基表指针，占8字节

};
class D : public B, public C{

};

int main(){
    B b;
    cout << "address B = " << &b << endl;
    cout << "address A = " << &b.a << endl;

    D d;
    cout << "address D = " << &d << endl;
    cout << "address A = " << &d.a << endl;
    // cout << d.a << endl;
    // d.run();

    cout << "sizeof A = " << sizeof(A) << endl;
    cout << "sizeof B = " << sizeof(B) << endl;
    cout << "sizeof C = " << sizeof(C) << endl;
    cout << "sizeof D = " << sizeof(D) << endl;
    // D d;
    // cout << d.a << endl;
    // d.run();

    /* D d;
    // d.run();
    d.B::run();
    d.C::run();
    ((B)d).run();
    ((C)d).run();

    int* a = nullptr;
    ((B*)a)->run();

    cout << "sizeof D = " << sizeof(D) << endl;
    // cout << "a = " << d.a << endl;
    cout << "a = " << d.B::a << endl;
    cout << "a = " << d.C::a << endl;
 */
    return 0;
}