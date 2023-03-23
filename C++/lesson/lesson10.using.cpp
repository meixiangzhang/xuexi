#include <iostream>
#include <vector>
// using namespace std;

using std::string;
using std::cout;
using std::endl;
using std::vector;

using INT_VEC = vector<long>;
using PF = void(*)();

void print(){
    cout << "kaikeba!\n";
}

class A{
private:
    int _x, _y;
protected:
    int _z;
public:
    int _w;

public:
    A(int x, int y):_x(x), _y(y){}
    A(int x):_x(x), _y(x){}
    void print(){
        cout << "A::print" << endl;
    }
};

class B : public A{
public:
    // B(int x, int y):A(x, y){}
    // B(int x):A(x){}
    using A::A;
    using A::_z;

protected:
    using A::_w;
    using A::print;
};

int main(){
    B b1(1, 2);
    B b2(12);
    B b3(b1);

    // cout << "w = " << b1._w << endl;
    cout << "z = " << b1._z << endl;

    // b1.print();

    cout << "123" << endl;

    INT_VEC arr;
    arr.push_back(1);

    PF func = &print;
    func();
    // void (*pFUN)() = &print;
    typedef void (*pFUN)();
    pFUN sunc = &print;
    sunc();



    return 0;
}


