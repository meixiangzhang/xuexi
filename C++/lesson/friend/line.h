#ifndef _LINE_H_
#define _LINE_H_
// #include "point.h"
class Point;
class Line {
public:
    Line(const Point& p1, const Point& p2);
    float getDistance();

private:
    Point *p1, *p2;
    // Point p; // 调用默认构造函数
};

#endif