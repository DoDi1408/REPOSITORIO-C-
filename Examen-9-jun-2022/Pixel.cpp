// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#include "Pixel.h"
Pixel::Pixel(){
    this->color = "000000";
}
Pixel::Pixel(int x_, int y_, std::string color_):Punto(x_,y_){
    this->color = color_;
}
std::string Pixel::getColor() const{
    return this->color;
}
void Pixel::setColor(std::string color_){
    this->color = color_;
}
std::string Pixel::mostrar(){
    return Punto::mostrar() + " color: " + this->color;
}