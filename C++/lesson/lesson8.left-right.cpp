#include <iostream>

using namespace std;

void test(int&){
    cout << __PRETTY_FUNCTION__ << endl;
}
void test(int&&){
    cout << __PRETTY_FUNCTION__ << endl;
}
// void print(int n){
//     cout << __PRETTY_FUNCTION__ << endl;
// }
// void print(int& n){
//     cout << __PRETTY_FUNCTION__ << endl;
// }
// void print(int&& n){
//     cout << __PRETTY_FUNCTION__ << endl;
//     // test(n);
//     test(forward<int&&>(n));
// }
void print(const int& n){
    cout << __PRETTY_FUNCTION__ << endl;
}
// void print(const int&& n){
//     cout << __PRETTY_FUNCTION__ << endl;
// }

int main(){
    int x, y;//等号左侧为左值
    x = 1;
    //右值：纯右值、将亡值
    // x+y;//右值 int operator=(const int&)
    // (x++)++;//x++返回的是右值，右值不能进行再操作
    // (++x)++;//++x返回的是左值引用
    // ++(++x);//++x返回的是左值引用

    print(x+y);
    print(x++);
    print(++x);

    int a = 1;
    int &b = a;
    const int c = 2;
    const int& d = a;

    int&& e = 9;
    // const int&& f = e;//e此时已有名字，不再为右值
    const int&& f = 10;
    e = 123;
    cout << "e = " << e << endl;

    print(a);//int&
    print(b);//int&
    print(c);//const int&
    print(d);//const int&
    print(e);//int&
    print(f);//const int&

    print(123);//int&&
    print(move(e));//const int&&
    print(move(f));//const int&&


    return 0;
}