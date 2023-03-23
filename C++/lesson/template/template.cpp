#include <iostream>

using namespace std;

class Point{
public:
    Point(int x, int y){}
    int operator+(const Point& p){
        return 123;
    }
};

// void print(int n){
//     cout << "call int function \n";
// }
// void print(float f){
//     cout << "call float function \n";
// }
// void print(double d){
//     cout << "call double function \n";
// }
// void print(Point p){
//     cout << "call Point function \n";
// }

template<typename T>
void print(T t){
    cout << "call template function \n";
}

template<>
void print(int n){
    cout << "call template int function \n";
}

// template<class T>
// T add(T a, T b){
//     cout << "add T" << endl;
//     return a + b;
// }

template<class T, class U>
// T add(T a, U b){
// auto add(T a, U b){
// decltype(T() + U()) add(T a, U b){
auto add(T a, U b)->decltype(a + b){
    // cout << "add T" << endl;
    return a + b;
}

// template<class T>
// T add(T& a, T& b){
//     cout << "add T&" << endl;
//     return a + b;
// }

// template<class T>
// T add(const T& a, const T& b){
//     cout << "add const T&" << endl;
//     return a + b;
// }

//函数匹配优先级：匹配普通函数  >  特化模板函数  >  通用模板函数
int main(){
    // print(1);
    // print(1.0f);
    // print(2.0);
    // print(Point());

    add(1, 2);
    add(2.0, 3.0);

    cout << add(1, 2.1) << endl;
    cout << add(2.1, 1) << endl;
    cout << add<int, int>(1, 2.1) << endl;
    cout << add<double, double>(2.1, 1) << endl;
    cout << add(Point(1, 2), Point(2, 3)) << endl;

    decltype(1+2) n;
    cout << typeid(n).name() << endl;

    return 0;
}