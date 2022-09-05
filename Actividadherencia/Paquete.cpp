#include <string>
#include <iostream>
using namespace std;
#include "Paquete.h"

Paquete::Paquete(){
    this->largo = 5;
    this->ancho = 5;
    this->profundidad = 5;
    this->peso = 5;
    this->pesoKg = 1.5;
}
Paquete::Paquete(Persona& receptor_, Persona& remitente_, double largo_, double ancho_, double profundidad_, double peso_, double pesoKg_):Envio(receptor_, remitente_){
    this->largo = largo_;
    this->ancho = ancho_;
    this->profundidad = profundidad_;
    if (peso_ <= 0)
    {
        peso_ = 10;
    }
    this->peso = peso_;
    if (pesoKg_ <= 0)
    {
        pesoKg_ = 1.5;
    }
    this->pesoKg = pesoKg_;
}
double Paquete::calculaCosto(){
    return Envio::calculaCosto() + this->peso * this->pesoKg;
}
double Paquete::getLargo() const{
    return this->largo;
}
double Paquete::getAncho() const{
    return this->ancho;
}
double Paquete::getProfundidad() const{
    return this->profundidad;
}
double Paquete::getPeso() const{
    return this->peso;
}
double Paquete::getPesoKg() const{
    return this->pesoKg;
}
void Paquete::setLargo(double largo_){
    this->largo = largo_;
}
void Paquete::setAncho(double ancho_){
    this->ancho = ancho_;
}
void Paquete::setProfundida(double profundidad_){
    this->profundidad = profundidad_;
}
void Paquete::setPeso(double peso_){
    if (peso_ <= 0)
    {
        peso_ = 10;
    }
    this->peso = peso_;
}
void Paquete::setPesoKg(double pesoKg_){
    if (pesoKg_ <= 0)
    {
        pesoKg_ = 1.5;
    }
    this->pesoKg = pesoKg_;
}
void Paquete::imprime(){
    Envio::imprime();
    cout << "Mi largo es " << this->largo << endl;
    cout << "Mi ancho es " << this->ancho << endl;
    cout << "Mi profundidad es " << this->profundidad << endl;
    cout << "Mi peso es " << this->peso << endl;
    cout << "Mi costo por Kg es " << this->pesoKg << endl;
}