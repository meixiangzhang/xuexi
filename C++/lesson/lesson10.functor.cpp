#include <iostream>
#include <algorithm>
using namespace std;

struct Print{
    int x, y;
    Print(int m, int n) : x(m), y(n){}
    Print& operator()(int n){
        if(n >= x && n <= y)
            cout << "int:" << n;
        return *this;
    }
    Print& operator()(const char* s){
        cout << s;
        return *this;
    }
};
void print(int n, int x, int y){

}

bool check(int n){
    if(n < 50)
        return true;
    return false;
}

struct CheckNumber{
    int min;
    int max;

    CheckNumber(int m, int n):min(m), max(n){}

    bool operator()(int n){
        if(n >= min && n <= max) return true;
        return false;
    }
};

int main(){
    Print print(100, 999);
    print(23)("hello")(456)("kaikeba")("\n");

    Print print2(1, 100);
    print2(23)("hello")(456)("kaikeba")("\n");

    int arr[] = {2,56,45,48,85,15,4,8,1,55};
    int count = count_if(arr, arr+10, check);
    cout << "count of < 50 = " << count << endl;

    int count2 = count_if(arr, arr+10, CheckNumber(50, 999));
    cout << "count > 50 = " << count2 << endl;

    int count3 = count_if(arr, arr+10, CheckNumber(1, 100));
    cout << "count > 50 = " << count3 << endl;



    return 0;
}
