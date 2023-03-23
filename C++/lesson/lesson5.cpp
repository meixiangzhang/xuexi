#include <iostream>
// objdump -d a.out 查看编译过程

using namespace std;

void print(int, int){
    cout << "int print" << endl;
}
void print(float, int){
    cout << "float print" << endl;
}
namespace master{
    class AAAA{};
}
// class A{};

int main(){

    // print(1);
    // print(1.0f);

    // cout << typeid(A).name() << endl;
    cout << typeid(master::AAAA).name() << endl;

    return 0;
}