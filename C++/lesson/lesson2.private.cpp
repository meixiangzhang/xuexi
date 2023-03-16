#include <iostream>

using namespace std;

class A {
private:
    int a;
public:
    void print() {
        cout << a << endl;
    }
};
class B {
private:
    int b;
};

int main() {
    A objA;
    objA.print();
    
    // cout << objA.a << endl;
    B objB;
    // cout << objB.b << endl;
    return 0;
}