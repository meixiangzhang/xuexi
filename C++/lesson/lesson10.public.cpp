#include <iostream>

using namespace std;

class Base{
private:
    int* resources;

public:
    Base():resources(new int[10]){

    }
    virtual ~Base(){
        delete[] resources;
    }
    Base(const Base& b){

    }
    Base& operator=(const Base& b){
        return *this;
    }
    Base& operator=(Base&& b){
        delete[] resources;
        resources = b.resources;
        b.resources = nullptr;
        cout << "move base" << endl;
        return *this;
    }
};
class Derived : public Base{
private:
    double* resources2;
public:
    Derived():resources2(new double[10]){

    }
    virtual ~Derived(){
        delete[] resources2;
    }

    Derived(const Derived& obj){

    }
    Derived& operator=(const Derived& obj){
        return *this;
    }
    Derived& operator=(Derived&& obj){
        Base::operator=(obj);
        delete[] resources2;
        resources2 = obj.resources2;
        obj.resources2 = nullptr;
        cout << "move derived" << endl;
        return *this;
    }
};

int main(){
    Base* b = new Base();
    Derived* d = new Derived();
    Derived* d2 = new Derived();
    // d2 = std::move(d);

    *b = std::move(*d);//只传递了父类部分的数据

    // Base b;
    // Derived d;
    // Derived d2;
    // // d2 = std::move(d);

    // b = std::move(d);//只传递了父类部分的数据

    return 0;
}









// #include <iostream>

// using namespace std;

// class B{
// public:
//     virtual void f() const{
//         cout << "B::f()\n";
//     }
//     virtual void g(int){
//         cout << "B::g(int)\n";
//     }
// };

// // class D : private B{
// class D : public B{
// public:
//     virtual void f() const{
//         cout << "D::f()\n";
//     }
//     virtual void g(bool){
//         cout << "D::g(bool)\n";
//     }
// };

// int main(){
//     B* p = new B;
//     p->f();
//     p->g(0);
//     delete p;
//     p = new D();
//     p->f();
//     p->g(0);
//     delete p;

//     return 0;
// }