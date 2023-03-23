#include <iostream>
#include <string>
#include <cstring>
// 有问题

using namespace std;

class People{
    friend int main();
private:
    string name;
    int age;
    char str[100];
    string s1;
    string s2;
public:
    People() 
        : name("master")
        , age(18)
        , s2(s1)
        , s1("123")
        // , s2("456")
    {
        cout << "default constructor" << endl;
    }
    explicit People(int n) : name(nullptr), age(n) {
        name = new char[20];
        memset(name, 0, 20);
        strcpy(name, "master");

        cout << "int constructor" << endl;
    }
    People(string s) : name(nullptr), age(18) {
        name = new char[20];
        memset(name, 0, 20);
        strcpy(name, s.c_str());

        cout << "string constructor" << endl;
    }

    People(const People& p) : name(), age(p.age)
    {
        name = new char[20];
        memset(name, 0, 20);
        strcpy(name, p.name);
        cout << "copy constructor" << endl;
    }

    ~People() {
        cout << "destructor" << endl;
        delete[] name;
    }

    void operator=(const People& p) {
        // name = new char[20];
        memset(name, 0, 20);
        strcpy(name, p.name);
        age = p.age;
        cout << "call operator = " << endl;
    }
};

int main() {
    People p(18);
    People p1(p);
    People p2(17);
    p2 = p;

    return 0;
}