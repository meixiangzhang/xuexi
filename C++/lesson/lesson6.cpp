#include <iostream>
using namespace std;
// 组合
class A{
public:
    void print(){
        cout << "call function A print" << endl;
    }
};

class B{
private:
    A a;
public:
    void print(){
        a.print();
    }
};

int main(){
    A a;
    B b;
    a.print();
    b.print();
    return 0;
}