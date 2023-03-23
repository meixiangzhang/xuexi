#include <iostream>
#include <cstring>

using namespace std;

class A{
private:
    char* _data;
public:
    A(const char* p){
        int size = strlen(p);
        // _data = (char*)malloc(size+1);
        _data = new char[size+1];
        strncpy(_data, p, size);
        _data[size] = '\0';
    }
    A(const A& a){
        cout << "copy constructor" << endl;
        int size = strlen(a._data);
        // _data = (char*)malloc(size+1);
        _data = new char[size+1];
        strncpy(_data, a._data, size);
        _data[size] = '\0';
    }
    A(A&& a) : _data(a._data){
        cout << "move constructor" << endl;
        a._data = nullptr;
    }

    void operator=(const A& a){
        cout << "operator = copy" << endl;

        if(_data) delete[] _data;

        int size = strlen(a._data);
        _data = new char[size+1];
        strncpy(_data, a._data, size);
        _data[size] = '\0';
    }
    void operator=(A&& a){
        cout << "operator = move" << endl;
        if(_data) delete[] _data;
        _data = a._data;
        a._data = nullptr;
    }

    virtual ~A(){
        if(_data) delete[] _data;
    }
    void test(){
        if(_data){
            cout << this << " " << _data << endl;
        }else{
            cout << this << " data is empty" << endl;
        }
    }
};

int main(){
    A a("abcdefg");
    a.test();

    A b(a);//copy
    b.test();

    A c(move(a));//move
    c.test();

    A d("123456");

    c = d;
    d.test();
    c = move(d);
    d.test();

    return 0;
}