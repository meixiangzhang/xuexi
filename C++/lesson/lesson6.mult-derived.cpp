#include <iostream>
using namespace std;

class Base1{
public:
    Base1(){
        cout << "Base1 constructor!" << endl;
    }
    ~Base1(){
        cout << "Base1 destructor!" << endl;
    }
    void test1(){
        cout << "Base1 :: test1" << endl;
    }
    int a;
};
class Base2{
public:
    Base2(){
        cout << "Base2 constructor!" << endl;
    }
    ~Base2(){
        cout << "Base2 destructor!" << endl;
    }
    void test2(){
        cout << "Base2 :: test2" << endl;
    }
    int b;
};
class Derived : public Base1, public Base2{
public:
    Derived(){
        cout << "Derived constructor!" << endl;
    }
    ~Derived(){
        cout << "Derived destructor!" << endl;
    }
    void test1(){
        // this->test1()
        Base1::test1();//子类调用父类方法只能通过<类名::方法名>来进行调用
        cout << "Derived test1" << endl;
    }
    void test2(){
        Base2::test2();
        cout << "Derived test2" << endl;
    }
    int c;
};

int main(){
    Derived derived;
    derived.test1();
    derived.test2();

    cout << "address a = " << &derived.a << endl;
    cout << "address b = " << &derived.b << endl;
    cout << "address c = " << &derived.c << endl;
    
    return 0;
}