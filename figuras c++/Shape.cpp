#include "Shape.h"
#include <iostream>
Shape::Shape(){
    this->x = 0;
    this->y = 0;
}
Shape::Shape(int x_ ,int y_){
    this->x = x_;
    this->y = y_;
}
int Shape::getX() const{
    return this->x;
}
int Shape::getY() const{
    return this->y;
}
void Shape::setX(int x_){
    x_ = this->x;
}
void Shape::setY(int y_){
    y_ = this->y;
}
std::string Shape::draw(){
    return "I am a shape";
}