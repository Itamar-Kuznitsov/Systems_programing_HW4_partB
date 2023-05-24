#pragma once
#include <math.h>
#include <iostream>
using namespace std;

namespace ariel {
    // Point class - (x,y)
    class Point {
    private:
        double x;
        double y;

    public:
        Point(double, double);
        Point();
        double distance(Point otherPoint);
        string print();
        static Point moveTowards(Point from, Point dest, double dist);
    };
}
