#include <math.h>
#include "line.h"
#include "point.h"

Line::Line(const Point& p1, const Point& p2) {
    this->p1 = new Point(p1);
    this->p2 = new Point(p2);
}
float Line::getDistance() {
    return sqrt((p1->_x - p2->_x) * (p1->_x - p2->_x) + (p1->_y - p2->_y) * (p1->_y - p2->_y));
}