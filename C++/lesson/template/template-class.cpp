#include <iostream>

using namespace std;

class Point{};

template<class T>
class A{
public:
    T t;

    // void print(T t){
    //     cout << "print---" << t << endl;
    // }
    template<class U>
    void print(U u){
        cout << "print---" << endl;
    }
};

template<>
class A<int>{
public:
    void print(int n){
        cout << "print---int = " << n << endl;
    }
};

template<int n>
class B{
public:
    static constexpr char* name = "class B template int";
    // static print(){
    //     cout << "----------------------class B template int\n";
    // }
};

template<>
class B<1>{
public:
    static constexpr char* name = "class B template 1";
    // static print(){
    //     cout << "----------------------class B template int\n";
    // }
};

template<>
class B<0>{
public:
    static constexpr char* name = "class B template 0";
    // static print(){
    //     cout << "----------------------class B template int\n";
    // }
};

int main(){
    A<double> a;
    cout << sizeof(A<double>) << " " << sizeof(a) << endl;
    cout << sizeof(A<int>) << endl;
    a.print(123);
    a.print(Point());
    a.print(1.0f);
    a.print(1);

    A<int> b;
    b.print(99);
    
    B<123> b1;
    B<0> b2;
    B<1> b3;

    cout << b1.name <<endl;
    cout << b2.name <<endl;
    cout << b3.name <<endl;


    return 0;
}