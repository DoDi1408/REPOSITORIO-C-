#include "CoordRect.h"
CoordRect::CoordRect(){
    x=0;
    y=0;
}
CoordRect::CoordRect(double xx, double yy){
    x=xx;
    y=yy;
}
double CoordRect::getX() const{
    return x;
}
double CoordRect::getY() const{
    return y;
}
void CoordRect::setX(double xx){
    x=xx;
}
void CoordRect::setY(double yy){
    y=yy;
}
CoordRect CoordRect::operator +(const CoordRect& otra){
    return CoordRect(this->x + otra.x,this->y + otra.y);
}
CoordRect CoordRect::operator +(const CoordPolar& otra){
    double x, y;
    x = otra.getR() * cos(otra.getAngulo()*M_PI/180);
    y = otra.getR() * sin(otra.getAngulo()*M_PI/180);
    return CoordRect(this->x + x,this->y + y);

}
ostream& operator <<(ostream& salida, const CoordRect& cr){
    salida << "(" << cr.x << "," << cr.y << ")";
    return salida; 
}
