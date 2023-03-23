#include <iostream>

using namespace std;

// class A final{//禁止继承
class A{
public:
    virtual void print() final {//禁止方法被覆盖override

    }
    virtual void test(){

    }
};

class B : public A{
public:
    // void print() override{
    // }
    void test() override{//修饰虚函数被覆盖

    }
    void test2() const{
        cout << "test2 const" << endl;
    }
    void test2(){
        cout << "test2" << endl;
    }
};

int main(){
    B b;
    b.test2();
    const B b2;
    b2.test2();

    return 0;
}