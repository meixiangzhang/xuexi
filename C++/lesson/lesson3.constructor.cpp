#include <iostream>
#include <string>

using namespace std;

class People{
    friend int main();
private:
    string name;
    int age;
};

int main() {
    People p;
    cout << "name = " << p.name << " sge = " << p.age << endl;
    return 0;
}