#include <iostream>
#include<math.h>
 
using namespace std;

class Point {
    // friend ostream& operator<<(ostream& os, const Point& p);
    friend float getDistance(const Point& p1, const Point& p2) {
        return sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
    }
    friend int main();
    friend class Line;
// public:
    Point(float x = 0, float y = 0) {
        _x = x;
        _y = y;
    }
    ostream& operator<<(ostream& os) {
        os << "member function x = " << this->_x << " y = " << this->_y << endl;
        return os;
    }
private:
    float _x, _y;
};

class Line {
public:
    float getDistance() {
        return sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
    }
    Line(const Point& start, const Point& end) {
        p1 = start;
        p2 = end;
    }

private:
    Point p1, p2;
};

// float getDistance(const Point& p1, const Point& p2) {
//     return sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
// }
// ostream& operator<<(ostream& os, const Point& p) {
//     os << "x = " << p._x << " y = " << p._y << endl;
//     return os;
// }

int main() {
    Point p1{1.2f, 3.4f}, p2{5.0f, 6.9f};
    cout << "distance = " << getDistance(p1, p2) << endl;
    Line line(p1, p2);
    cout << line.getDistance() << endl;

    // cout << p1 << endl;
    p1 << cout <<endl;

    return 0;
}