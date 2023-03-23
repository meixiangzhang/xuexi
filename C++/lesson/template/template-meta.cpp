#include <iostream>

using namespace std;

template<int M, int N>
struct Meta_Add
{
    static constexpr int value = M + N;
};

template<int N>
struct Meta_Sum
{
    static constexpr int value = N + Meta_Sum<N-1>::value;
};

template<>
struct Meta_Sum<1>
{
    static constexpr int value = 1;
};

template<bool b, class A, class B>
class IFELSE
{
public:
    using type = A;
};

// template<class A, class B>
// class IFELSE<true, A, B>
// {
// public:
//     using type = A;
// };

template<class A, class B>
class IFELSE<false, A, B>
{
public:
    using type = B;
};


// template<bool b, class A, class B>
// struct IFELSE
// {
//      using type = A;
// };

// // template<class A, class B>
// // struct IFELSE<true, A, B>
// // {
// //      using type = A;
// // };
// template<class A, class B>
// struct IFELSE<false, A, B>
// {
//      using type = B;
// };

string AreaCode(int code){
    switch(code)
    {
        case 10:
            return "beijing";
        case 21:
            return "shanghai";
        case 571:
            return "hangzhou";
        default:
            return "zhongguo";
    }
}

template<int code>
class Meta_AreaCode{
public:
    static constexpr auto value = "zhongguo";
};
template<>
class Meta_AreaCode<10>{
public:
    static constexpr auto value = "beijing";
};
template<>
class Meta_AreaCode<21>{
public:
    static constexpr auto value = "shanghai";
};
template<>
class Meta_AreaCode<571>{
public:
    static constexpr auto value = "hangzhou";
};

int main(){

    cout << Meta_Add<123, 456>::value <<endl;

    //for/while
    cout << Meta_Sum<100>::value <<endl;//5050

    //实现IF ELSE
    IFELSE<true, int, double>::type a;//int
    IFELSE<false, int, double>::type b;//double
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    std::conditional<true, int, double>::type a1;//int
    std::conditional<false, int, double>::type b1;//double
    cout << typeid(a1).name() << endl;
    cout << typeid(b1).name() << endl;

    //switch
    cout << Meta_AreaCode<10>::value << endl;
    cout << Meta_AreaCode<21>::value << endl;
    cout << Meta_AreaCode<571>::value << endl;
    cout << Meta_AreaCode<100>::value << endl;

    return 0;
}
