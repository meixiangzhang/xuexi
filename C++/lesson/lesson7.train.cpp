#include <iostream>
using namespace std;

//练习：
// 重写(overwrite) : Animal类->Dog类、Cat类
// 覆盖(override) : Animal类->Dog类、Cat类

class Animal{
public:
    virtual void run(){
        cout << "Animal Cannot Run" << endl;
    }
    virtual void eat(){
        cout << "Animal Cannot Eat" << endl;
    }
    virtual void speak(){
        cout << "Animal Cannot Speak" << endl;
    }
    void actionEat(){
        this->run();
        this->eat();
        this->speak();
    }
};
class Cat : public Animal{
public:
    void run(){
        cout << this << "Cat Run" << endl;
    }
    void eat(){
        cout << this << "Cat Eat" << endl;
    }
    void speak(){
        cout << this << "Cat Speak" << endl;
    }
};
class Dog : public Animal{
public:
    void run(){
        cout << this << "Dog Run" << endl;
    }
    void eat(){
        cout << this << "Dog Eat" << endl;
    }
    void speak(){
        cout << this << "Dog Speak" << endl;
    }
};


int main(){
    Animal* animals[10];
    for(int i = 0; i < 10; i++){
        if(i%2 == 1){
            animals[i] = new Cat();
        }else{
            animals[i] = new Dog();
        }
    }
    for(auto animal : animals){
        animal->actionEat();
    }
    return 0;
}