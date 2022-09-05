#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
class Rectangle:public Shape{
    public:
        Rectangle();
        Rectangle(int, int, int, int);
        int getHeight() const;
        int getWidth() const;
        void setHeight(int);
        void setWidth(int);
        double area() override;
        std::string draw() override;
    private:
        int height, width;
};
#endif