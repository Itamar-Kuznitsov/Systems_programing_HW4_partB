#include <iostream>
#include "point.hpp"

using namespace std;
using namespace ariel;

// constructor:
Point::Point(double x_, double y_)
    : x(x_), y(y_) {}

// empty constructor
Point::Point() {}

// calculate distance
double Point::distance(Point otherPoint) {
    double first = pow((x - otherPoint.x), 2);
    double second = pow((y - otherPoint.y), 2);
    return sqrt(first + second);
}

// print point in the form of: (x, y)
string Point::print() {
    string res = "(" + to_string(x) + "," + to_string(y) + ")";
    return res;
}

// TODO: Implement moveTowards()
Point Point::moveTowards(Point src, Point dest, double distance) {
    if(distance < 0){
        throw invalid_argument("distance cant be negative");
    }

    double dx = dest.x - src.x;
    double dy = dest.y - src.y;
    double curr_distance = sqrt(dx*dx + dy*dy);

    if(curr_distance <= distance){
        return dest;
    }

    double rat = distance / curr_distance;
    double newX = src.x + rat * dx;
    double newY = src.y + rat * dy;
    return Point(newX,newY);
}



























// #include <iostream>
// #include "point.hpp"

// using namespace std;
// using namespace ariel;

// // constructor:
// Point:: Point(double x_, double y_)
//     : x(x_), y(y_) {}

// // empty constructor
// Point:: Point(){}

// // calculate distance
// double Point:: distance(Point otherPoint){
//     int first = pow((this->x - otherPoint.x), 2);
//     int second = pow((this->y - otherPoint.y), 2);
//     return sqrt(first + second);
// }

// // print point in a form of : (x,y)
// string Point:: print(){
//     string res = "(" + to_string(this->x) + "," + to_string(this->y) + ")" ;
//     return res;
// }

// // TODO(I): --> 
// Point Point:: moveTowards(Point from, Point dest, double dist){
//     return Point();
// }