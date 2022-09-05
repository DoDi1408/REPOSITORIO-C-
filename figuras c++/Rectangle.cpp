#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(){
    this->width = 1;
    this->height = 1;
}
Rectangle::Rectangle(int x_,int y_,int height_,int width_):Shape(x_,y_){
    this->width = width_;
    this->height = height_;
}
int Rectangle::getHeight() const{
    return this->height;
}
int Rectangle::getWidth() const{
    return this->width;
}
void Rectangle::setHeight(int height_){
    this->height = height_;
}
void Rectangle::setWidth(int width_){
    this->width = width_;
}
double Rectangle::area(){
    return this->height * this->width;
}
std::string Rectangle::draw(){
    return Shape::draw() + ": Rectangle";
}