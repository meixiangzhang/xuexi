#include <iostream>
using namespace std;

class Base{
protected:
    int _a;
public:
    Base(){
        cout << "default constructor Base" << endl;
    }
    Base(int n):_a(n){
        cout << "int constructor Base" << endl;
    }
    Base(const Base& base){
        cout << "copy constructor Base" << endl;
    }
    ~Base(){
        cout << "destructor Base" << endl;
    }

    void f(){
        cout << "call Base f()" << endl;
    }
};
class Derived : public Base{
private:
    int _b;
public:
    Derived(){// 编辑器会自动加上:Base()
        cout << "default constructor Derived" << endl;
    }
    Derived(int n):Base(n), _b(_a){
        cout << "int constructor Derived" << endl;
    }
    Derived(const Derived& derived):Base(derived){
        cout << "copy constructor Derived" << endl;
    }
    ~Derived(){
        cout << "destructor Derived" << endl;
    }
    void operator=(const Derived& derived){
        cout << "operator = Derived" << endl;
    }

    void g(){
        cout << "call Derived g()" << endl;
    }
};

int main(){
    // Base base;
    Derived derived(1);
    // Derived derived2(derived);
    Derived derived2;
    derived2 = derived;
    // base.f();
    // base.g();
    // derived.f();
    // derived.g();

    // cout << "sizeof Base = " << sizeof(Base) << " sizeof Derived = " << sizeof(Derived) << endl;

    return 0;
}