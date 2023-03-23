#include <iostream>
#include <stdio.h>
using namespace std;
struct Base{
    int x, y;
    Base(){}
    virtual ~Base(){
        cout << "Base Destructor" << endl;
    }
    virtual void test(){
        cout << "Call Member Test Func" << endl;
    }
    virtual void test(int n){
        cout << "Call Member Test Int Func n = " << n << endl;
    }
    static void staticFunc(){
        cout << "Static Function" << endl;
    }
};
struct Derived : public Base{
    int* ptr;
    Derived(){
        // ptr = new int();
    }
    ~Derived(){
        cout << "Derived Destructor" << endl;
        // delete ptr;
    }
    void test() override{
        cout << "Derived Member Func" << endl;
    }
};

void func(){
    cout << "call func" << endl;
}
void func2(int){
    cout << "call func int" << endl;
}

void output_obj_address(void* ptr, int size){
    unsigned char* p = (unsigned char*)ptr;
    for(int i = 0; i < size; i++){
        printf("%02X ", p[i]);
    }
    printf("\n");
}

int main(){
    Base* base = new Base();
    Derived* derived = new Derived();
    Base* pBase = derived;//编译器会自动进行类型升级转换
    // Derived* pDerived = base;//报错

    Derived* pDerived = (Derived*)base;//操作时需要自己去控制安全性
    pDerived->test();
    cout << pDerived->ptr << endl;//这里的访问是错误的，无法保证数据的安全

    Derived* pDerived1 = static_cast<Derived*>(base);//类似C的强制转换
    Derived* pDerived2 = dynamic_cast<Derived*>(pBase);//动态转换，RTTI技术
    cout << pDerived2 << endl;//依赖virtual函数实现
    // pDerived1->test();
    // pDerived2->test();

    const Derived* c_derived = new Derived();
    Derived* pDerived3 = const_cast<Derived*>(c_derived);//去掉类型的const
    // Derived pDerived4 = const_cast<Derived>(*derived);//只支持指针类型和引用类型
    pDerived3->test();

    unsigned long ptr = reinterpret_cast<unsigned long>(derived);
    Derived* pDerived5 = reinterpret_cast<Derived*>(ptr);
    pDerived5->test();

    // Base base;
    // Derived derived;
    // Base& base2 = derived;

    // output_obj_address(&base, sizeof(Base));
    // output_obj_address(&derived, sizeof(Derived));
    // output_obj_address(&base2, sizeof(Derived));
    // base2.test();

    // typedef void (*pClassFunc1)(void*);//类成员函数最终形式
    // typedef void (*pClassFunc2)(void*, int);//类成员函数最终形式
    // cout << "===================begin==============\n";
    // ((pClassFunc1**)&derived)[0][0](&derived);
    // cout << "===================end================\n";


    /* void (*pFunc)() = func;
    pFunc();
    typedef void(*PFUNC)();
    typedef void(*PFUNC_INT)(int);
    PFUNC pfunc1 = func;
    pfunc1(); 
    PFUNC_INT pfunc2 = func2;
    pfunc2(123);

    PFUNC pfunc3 = &Base::staticFunc;
    pfunc3();

    typedef void (Base::*PClassFuncTest)();//类成员函数
    typedef void (Base::*PClassFuncTestInt)(int);//类成员函数
    PClassFuncTest pClassFT = &Base::test;
    PClassFuncTestInt pClassFTI = &Base::test;
    Base base;
    (base.*pClassFT)();
    (base.*pClassFTI)(123); */

    return 0;
}