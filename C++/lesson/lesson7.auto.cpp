#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Car{
public:
    virtual ~Car(){
        cout << "Car destructor" << endl;
    }
};
class BMW : public Car{
private:
    char* _name;
public:
    BMW(const char* s): _name(nullptr){
        int len = strlen(s);
        _name = new char[len + 1];
        strncpy(_name, s, len);
        _name[len] = '\0';
    }
    ~BMW(){
        // Car::~Car();//编译器帮你自动加上
        cout << "BMW destructor" << endl;
        delete[] _name;
    }
};
class IBuilder{
public:
    virtual ~IBuilder(){}
    virtual void buildEngine() = 0;
    virtual void buildWheel() = 0;
    virtual void buildSeat() = 0;
    virtual Car* buildCar() = 0;
};
class BMWBuiler : public IBuilder{
public:
    void buildEngine(Car* car){

    }
    void buildWheel(Car* car){
        
    }
    void buildSeat(Car* car){

    }
    Car* buildCar(){
        Car* car = new BMW("740");
        buildEngine(car);
        buildWheel(car);
        buildSeat(car);
        return car;
    }
};

class AutoSystem{
private:
    static std::map<string, Car*> _cars;
    static std::map<string, IBuilder*> _builders;
public:
    static void createBMW(string name){
        if(name == "BMW"){
            Car* pCar = _builders["bmw"]->buildCar();
        }
    }
};

int main(){
    // Car* p = new BMW();
    Car* p = new BMW("BMW740");

    delete p;

    return 0;
}