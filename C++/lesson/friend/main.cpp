#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

int main() {
    Point p1{23.1f, 4.26f}, p2{2.3f, 56.4f};
    Line line(p1, p2);

    cout << line.getDistance() << endl;
    
    return 0;
}