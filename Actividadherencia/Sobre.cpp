#include <string>
#include <iostream>
using namespace std;
#include "Sobre.h"

Sobre::Sobre(){
    this->largo = 10;
    this->ancho = 10;
}
Sobre::Sobre(Persona& receptor_, Persona& remitente_, double largo_, double ancho_):Envio(receptor_, remitente_){
    this->largo = largo_;
    this->ancho = ancho_;
}
double Sobre::calculaCosto(){
    if ((this->largo >= 25) || (this->ancho >= 30))
    {
        return Envio::calculaCosto() + 50;
    }
    else
    {
        return Envio::calculaCosto();
    }
}
double Sobre::getLargo() const{
    return this->largo;
}
double Sobre::getAncho() const{
    return this->ancho;
}
void Sobre::setLargo(double largo_){
    this->largo = largo_;
}
void Sobre::setAncho(double ancho_){
    this->ancho = ancho_;
}
void Sobre::imprime(){
    Envio:imprime();
    cout << "Mi largo es " << this->largo << endl;
    cout << "Mi ancho es " << this->ancho << endl;
}