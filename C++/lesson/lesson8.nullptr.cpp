#include <iostream>

using namespace std;

void print(long n){
    cout << "call function long" << endl;
}

void print(void* ptr){
    cout << "call function pointer" << endl;
}

int main(){
    cout << typeid(NULL).name() << endl;
    print(NULL);
    int* p= nullptr;
    print(p);


    cout << typeid(nullptr).name() << endl;

    return 0;
}