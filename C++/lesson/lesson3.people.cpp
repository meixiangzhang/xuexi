#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class People{
private:
    const string name;
    mutable int age;
    float height;
    float weight;

private:
    People() : name("master"), age(0), height(0), weight(0) {

    };
    ~People() {

    };

public:
    //string getName(const People* this)
    string getName() const{
        // addAge();
        age++;
        return name;
    }
    void addAge() const{
        age++;
    }
    bool init(){
        // do something init
        return true;
    }
    void start(){

    }

public:
    static vector<People*> arr;
    static int count;
    static People* create(){
        People::count++;
        People* p = new People();
        p->init();
        p->start();
        arr.push_back(p);
        return new People();
    }
    static void release(People* p){
        People::count--;
        for(auto it = arr.begin(); it != arr.end(); ++it){
            if(p == *it){
                arr.erase(it);
                break;
            }
        }
        delete p;
    }
    static void clear(){
        for(auto it : arr){
            delete it;
        }
    }
};

int People::count = 0;

vector<People*> People::arr;
int main() {
    // People* p = new People();
    // p->init();
    // p->start();
    // arr.push_back(p);

    cout << "size = " << sizeof(People) << endl;
    // People p; // 错误，不允许构造
    cout << People::count << endl; // 输出0
    People* p1 = People::create(); // 可以
    cout << People::count << endl; // 输出1
    // delete p1; // 错误
    People::release(p1); // 正确释放
    return 0;
}