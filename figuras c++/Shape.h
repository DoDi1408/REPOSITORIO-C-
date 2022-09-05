#ifndef SHAPE_H_ 
#define SHAPE_H_ 
#include <iostream>
class Shape{
    public:
        Shape();
        Shape(int,int);
        int getX() const;
        int getY() const;
        void setX(int) ;
        void setY(int);
        virtual std::string draw();
        virtual double area() = 0;
    private:
        int x, y;
};
#endif