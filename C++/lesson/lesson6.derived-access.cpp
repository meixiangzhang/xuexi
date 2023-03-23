#include <iostream>
using namespace std;
class A{
private:
    int a1;
protected:
    int a2;
public:
    int a3;
};

class B : public A{
public:
    void test(){
        // cout << this->a1 << endl;//private无法访问
        cout << this->a2 << endl;//protected可以让子类访问
        cout << this->a3 << endl;//public可以让外部访问
    }
};

class C : protected A{
public:
    void test(){
        // cout << this->a1 << endl;//private无法访问
        cout << this->a2 << endl;//protected可以让子类访问
        cout << this->a3 << endl;//public可以让外部访问
    }
};

class D : private A{
public:
    void test(){
        // cout << this->a1 << endl;//private无法访问
        cout << this->a2 << endl;//protected可以让子类访问
        cout << this->a3 << endl;//public可以让外部访问
    }
};

class E : protected B{
public:
    void test(){
        // cout << this->a1 << endl;//private无法访问
        cout << this->a2 << endl;//protected可以让子类访问
        cout << this->a3 << endl;//public可以让外部访问
    }
};


int main(){
    B b;
    // cout << b.a1 << endl;//private 无法访问
    // cout << b.a2 << endl;//protected 无法访问
    cout << b.a3 << endl;//public 可以访问

    // C c;
    // cout << c.a1 << endl;//private 无法访问
    // cout << c.a2 << endl;//protected 无法访问
    // cout << c.a3 << endl;//protected 无法访问

    // D d;
    // cout << d.a1 << endl;//private 无法访问
    // cout << d.a2 << endl;//private 无法访问
    // cout << d.a3 << endl;//private 无法访问
    // E e;
    // cout << e.a1 << endl;//private 无法访问
    // cout << e.a2 << endl;//protected 无法访问
    // cout << e.a3 << endl;//protected 无法访问

    return 0;
}