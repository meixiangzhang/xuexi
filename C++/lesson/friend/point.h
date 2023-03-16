#ifndef _Point_H_
#define _Point_H_

#include "line.h"

// class Line;
class Point {
    // friend class Line;
    friend float Line::getDistance();

public:
    Point(float x = 0, float y = 0);

private:
    float _x, _y;
};

#endif