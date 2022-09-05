#ifndef CIRCLE_H_ 
#define CIRCLE_H_
#include "Shape.h"
#include <iostream>
class Circle:public Shape{
    public:
        Circle();
        Circle(int,int,int);
        int getRadius() const;
        void setRadius(int);
        double area() override;
        double circumference();
        std::string draw() override;
    private:
    int radius;
};

#endif 