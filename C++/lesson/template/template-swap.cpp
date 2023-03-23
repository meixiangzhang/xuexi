#include <iostream>
//出错了，我没看懂
using namespace std;

namespace master{
    void print(int& n){
        cout << "print(int&)" << endl;
    }
    void print(int&& n){
        cout << "print(int&&)" << endl;
    }

    template<class T>
    void swap(T&& a, T&& b){//universal reference
        print(std::forward<T>(a));
        cout << "std::is_reference(T) = " << std::is_reference<T>::value <<endl;
        typename std::remove_reference<T>::type c = a;//int
        // T c = a;
        a = b;
        b = c;
    }
}

int main(){
    int a = 123, b = 456;

    master::swap(a, b);//T -> int& -> int&&& 引用坍塌，类型坍塌 -> int&
    // master::swap(move(a), 999);
    cout << "a = " << a << " b = " << endl;
    int c = 123;
    master::swap(999, move(c));

    return 0;
}