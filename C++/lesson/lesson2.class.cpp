#include <iostream>
#pragma pack(1) // 取消内存对齐

using namespace std;

class People {
public:
    // string name; // 32
    char name[10];
    int age; // 4 -> 8
    double weight; // 8
    double height; // 8

    void say(string word);
    void run();
};

class A {
    // int c;
    int a;
    double b;
    int c;

};

class B {};

int main() {
    People p;
    B b;
    B* b1 = new B();
    B* b2 = new B();
    sizeof(int);
    sizeof(1);
    cout << "size of string = " << sizeof(string) << endl;
    cout << "size of People = " << sizeof(People) << " size of p = " << sizeof(p) << endl;

    cout << "adress name = " << &p.name << endl;
    cout << "adress age = " << &p.age << endl;
    cout << "adress weight = " << &p.weight << endl;
    cout << "adress height = " << &p.height << endl;

    cout << "size of A = " << sizeof(A) << endl;
    cout << "size of B = " << sizeof(B) << endl;


    return 0;
}