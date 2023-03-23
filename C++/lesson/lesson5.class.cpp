#include <iostream>

using namespace std;

class Point{
private:
    float _x, _y;

public:
    Point():_x(0), _y(0){

    }
    Point(float x, float y):_x(x), _y(y){

    }

    void print(int n){
        cout << " x = " << (int)_x << " y = " << (int)_y << endl;
    }
    void print(float n){
        cout << " x = " << _x << " y = " << _y << endl;
    }

    void print(int n, int m){// printii

    }
    // void print(int a, int b){// printii

    // }
    void print(float f, int i){// printfi

    }
    void print(int i, float f){// printif

    }
    void print(int i, float f, int n){// printifi

    }

    Point operator+(const Point& p){
        // Point p(*this);
        // p._x += p._x;
        // p._y += p._y;
        return Point(this->_x += p._x, this->_y += p._y);
    }
    Point operator++(int){// operator++i
        Point p(this->_x, this->_y);
        this->_x++;
        this->_y++;
        return p;
    }
    Point& operator++(){// operator++
        this->_x++;
        this->_y++;
        return *this;
    }
    Point& operator+=(const Point& p){
        this->_x += p._x;
        this->_y += p._y;
        return *this;
    }
    float operator*(const Point& p){
        return this->_x*p._x + this->_y*p._y;
    }

    // add()
    // mult()

    friend void print(const Point& p, int);
    friend void print(const Point& p, float);
    friend ostream& operator<<(ostream& os, const Point& p);
};

void print(const Point& p, int){
        cout << " x = " << (int)p._x << " y = " << (int)p._y << endl;
}
void print(const Point& p, float){
        cout << " x = " << p._x << " y = " << p._y << endl;
}

ostream& operator<<(ostream& os, const Point& p){
    os << " x = " << p._x << " y = " << p._y << endl;
    return os;
}


int main(){

    Point p1{1.2f, 3.4f}, p2{2.3f, 3.4f};
    p1.print(1);
    p2.print(1.0f);
    p2.print(float(1.0)); // double  1.0->int float

    print(p1, 1);
    print(p2, 1.0f);

    cout << p1 + p2 << endl;
    cout << p1++ << endl;
    cout << ++p1 << endl;
    cout << (p1 += p2) << endl;
    cout << p1*p2 << endl;

    cout << p1 << endl;// cout << " x = " << _x << " y = " << _y << endl;

    return 0;
}