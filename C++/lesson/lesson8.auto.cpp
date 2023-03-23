#include <iostream>
#include <vector>
using namespace std;

void print(auto i){

}
class A{
private:
    // auto _n;
    // static auto _n;
    // static auto n = 1;
public:
    A(int n, int m, int k){}
};

// static auto A::_n = 123;
int main(){
    auto n = 1;
    cout << typeid(n).name() << endl;

    print(123);
    print(123.0);

    // auto arr = {1};
    // A a = {1, 2, 3};//这里是作为构造函数的形参去匹配构造函数的

    vector<int> vec1(10);
    vector<int> vec2{10};

    for(auto i : vec1){
        cout << i << endl;
    }
    cout << "-------------\n";
    for(auto i : vec2){
        cout << i << endl;
    }

    return 0;
}