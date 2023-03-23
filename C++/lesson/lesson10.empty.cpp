#include <iostream>

using namespace std;

struct A{

};
struct AA{

};

struct B : public A{//A类的空间被优化了
// A a;
};

class C : public A, public B{//空基类优化只发生在一层继承

};
class D : public A, public AA{

};
class E : public B{

};

int main(){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    
    
    A arr[10];
    A* p1 = new A();
    A* p2 = new A();

    for (auto a : arr){

    }

    return 0;
}