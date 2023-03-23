#include <iostream>

using namespace std;

namespace master{

template<class T>
void print(const T& t){
    cout << t << endl;
}

template<class T, class ...ARGS>
void print(const T& t, ARGS ...args){
    cout << t << " ";
    print(args...);
}

template<class T>
T sum1(const T& t){
    return t;
}

template<class T, class ...ARGS>
T sum1(const T& t, ARGS ...args){
    return t + sum1(args...);
}

template<typename T>
T sum2(T t){
    if(t == 1) return 1;
    return t + sum2(t - 1);
}

template<int i, class T, class ...ARGS>
struct TYPE{
    using type = typename TYPE<i-1, ARGS...>::type;
};

template<class T, class ...ARGS>
struct TYPE<0, T, ARGS...>{
    using type = T;
};

template<class T>
struct TYPE<0, T>{
    using type = T;
};

}

int main(){
    master::print(666, "123", 456, "kaikeba", 789, "\n");

    cout << master::sum1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;//1-10累加
    cout << master::sum2(100) << endl;//1-100累加求和 5050

    master::TYPE<1, int, double, float, int>::type n1;//double
    master::TYPE<2, int, double, float, int, float>::type n2;//float
    cout << "typeid(n1) = " << typeid(n1).name() <<" size = " << sizeof(n1) <<endl;
    cout << "typeid(n2) = " << typeid(n2).name() <<" size = " << sizeof(n2) <<endl;


    return 0;
}