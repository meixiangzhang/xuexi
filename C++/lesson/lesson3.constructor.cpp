#include <iostream>
#include <string>

using namespace std;

struct A{
    char str[100];
    string s1;
    string s2;
};

class People{
    friend int main();
private:
    string name;
    int age;
    // A a;
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
    // People() { // 1、先调用name的默认构造函数    2、调用string operator= 操作符重载函数
    //     name = "master";
    //     age = 18;
    //     s1 = "123";
    //     s2 = "456";
    // }
    // implicit
    explicit People(int n) : name("kaikeba"), age(n) {
        cout << "int constructor" << endl;
    }
    People(string s) : name(s), age(18) {
        cout << "string constructor" << endl;
    }

    People(const People& p) : name(p.name), age(p.age)
    {
        cout << "copy constructor" << endl;
    }

    void operator=(const People& p) {
        name = p.name;
        age = p.age;
        cout << "call operator = " << endl;
    }
};

void add(int& a) {
    a += 1;
}

int main() {
    People p;
    cout << "name = " << p.name << " age = " << p.age << endl;
    cout << "s1 = " << p.s1 << " s2 = " << p.s2 << endl;

    People p2(20); // int
    People p3("kaikeba"); // string
    People p4(p);

    People p5;
    p5 = p;

    People p6 = People(18);

    int a = 123;
    int& b = a;
    int& c = a;

    a = 456;
    b = 654;
    cout << "a = " << a << " b = " << b << endl;
    cout << "&a = " << &a << " &b = " << &b << endl;

    add(a);
    cout << "a = " << a << endl;

    return 0;
}