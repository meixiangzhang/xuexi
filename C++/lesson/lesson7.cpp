#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class A{
public:
    virtual void print(){//虚函数表指针
        cout << "A::print" << endl;
    }
};
class B : public A{//B类也有自己的虚函数表
public:
    int _b;
public:
    void print() override{
        cout << "B::print" << this << endl;
    }
};
class C : public A{
public:
    void print() override{
        cout << "C::print" << this << endl;
    }
};

void print(vector<A*>& arr){
    for(auto it : arr){
        it->print();
    }
}

int main(){
    A a;
    B b;
    a.print();
    b.print();

    A& obj = b;//发生了类型转换，这里进行转换时，虚函数表的信息不会发生变化
    obj.print();
    // cout << &A::print << endl;
    // cout << &B::print << endl;
    // printf("%p\n", &A::print);
    // printf("%p\n", &B::print);
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    //子类可以转换为父类，而且这个过程是自动的
    //父类是不可以转换为子类的
    // B* pB = new A();//错误，父类不可以转子类
    // cout << pB->_b << endl;

    //动态多态的作用
    A* pA = new B();//可以，子类可以转父类
    pA->print();

    vector<A*> arr;
    arr.push_back(new B());
    arr.push_back(new C());
    arr.push_back(new B());
    arr.push_back(new C());
    print(arr);

    // virtual关键字不能修饰的函数有哪些？
    // 1、构造函数 ：不可以
    // 2、全局函数 ：全局函数不可以
    // 3、静态成员函数 ：全局函数不可以
    // 4、友元函数 ：全局函数不可以
    // 5、inline 在编译时进行展开

    return 0;
}