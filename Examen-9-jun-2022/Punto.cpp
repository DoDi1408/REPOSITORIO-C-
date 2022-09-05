// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#include "Punto.h"

Punto::Punto(){
    this->x = 1;
    this->y = 1;
}
Punto::Punto(int x_, int y_){
    this->x = x_;
    this->y = y_;
}
std::string Punto:: mostrar(){
    std::string stringX, stringY;
    stringX =std::to_string(this->x);
    stringY =std::to_string(this->y);
    return "Coordenadas del punto x: " + stringX + " y: " + stringY;
}
std::ostream &operator << (std::ostream & salida, Punto* miPunto){
    salida << miPunto->mostrar();
    return salida;
}
int Punto::getX() const{
    return this->x;
}

int Punto::getY() const{
    return this->y;
}
void Punto::setX(int x_){
    this->x = x_;
}
void Punto::setY(int y_){
    this->y = y_;
}