#include <iostream>

using namespace std;

template<int N>
struct judge
{
    static constexpr bool value = (N >= 60);
};


template<int N>
struct score
{
    static constexpr const char* value = judge<N>::value ? "good" : "bad";
};

template<int N>
struct judgeEven
{
    static constexpr bool value = (N % 2 ? false : true);
};


template<int N>
struct is_even
{
    static constexpr const char* value = judgeEven<N>::value ? "YES" : "NO";
};


template<int i, int n>
struct NEXTI
{
    static constexpr int value = n % i ? i + 1 : 0;
};
template<int i, int n>
struct NEXTN
{
    static constexpr int value = i * i <= n ? n : 0;
};
template<int i, int n>
struct judgePrime
{
    static constexpr int value = judgePrime<NEXTI<i, n>::value, NEXTN<i, n>::value>::value;
};
template<int n>
struct judgePrime<0, n>
{
    static constexpr bool value = false;
};
template<int i>
struct judgePrime<i, 0>
{
    static constexpr bool value = true;
};
template<int N>
struct is_prime
{
    static constexpr const char* value = judgePrime<2, N>::value ? "YES" : "NO";
};
template<>
struct is_prime<2>
{
    static constexpr const char* value = "YES";
};

int main(){
    cout << score<60>::value << endl;//good
    cout << score<40>::value << endl;//bad

    cout << is_even<2>::value << endl;//YES
    cout << is_even<3>::value << endl;//NO

    cout << is_prime<3>::value << endl;//YES
    cout << is_prime<10>::value << endl;//NO
    cout << is_prime<97>::value << endl;//YES
    cout << is_prime<9997>::value << endl;//NO
    cout << is_prime<2>::value << endl;//NO

    return 0;
}