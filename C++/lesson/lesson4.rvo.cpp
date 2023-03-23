#include <iostream>

// g++ lesson4.rvo.cpp -fno-elide-constructors 关闭RVO
using namespace std;

class People{
public:
    People(){
        cout << "default constructor " << this << endl;
    }
    People(string name){
        cout << "string constructor " << this << endl;
    }
    People(const People& p){
        cout << "copy constructor " << this << endl;
    }

private:
    const static int count = 123;

    string name;
    int age;
    float height;
    float weight;
};

People func(){
    People temp_a("master");
    return temp_a;
}

int main() {
    People p = func();
    return 0;
}