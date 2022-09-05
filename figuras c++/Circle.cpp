#include "Circle.h"
#include <iostream>

Circle::Circle(){
    this->radius=1;
}
Circle::Circle(int x_,int y_,int r_):Shape(x_,y_){
    this->radius = r_;
}
int Circle::getRadius() const{
    return this->radius;
}
void Circle::setRadius(int r_){
    this->radius = r_;
}
double Circle::area(){
    return 3.1416*this->radius*this->radius;
}
std::string Circle::draw(){
    return Shape::draw() + ": Circle";
}
double Circle::circumference(){
    return 2 * 3.1416 * this->radius;
}