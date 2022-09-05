// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#include "Punto3d.h"

Punto3d::Punto3d(){
    this->z = 1;
}
Punto3d::Punto3d(int x_, int y_, int z_):Punto(x_,y_){
    this->z = z_;
}
std::string Punto3d::mostrar(){
    std::string stringZ;
    stringZ =std::to_string(this->z);
    return Punto::mostrar() + " z: " + stringZ;
}
int Punto3d::getZ() const{
    return this->z;
}
void Punto3d::setZ(int z_){
    this->z = z_;
}
