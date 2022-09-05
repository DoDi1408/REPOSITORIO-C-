#include "Envio.h"
#include <string>
#include <iostream>
using namespace std;
Envio::Envio(){
    this->receptor = Persona();
    this->remitente = Persona();
    this->precio = 100;
}
Envio::Envio(Persona& receptor_, Persona& remitente_){
    this->receptor = receptor_;
    this->remitente = remitente_;
    this->precio = 100;
}
Persona Envio::getRemitente() const{
    return this->remitente;
}
Persona Envio::getReceptor() const{
    return this->receptor;
}
double Envio::getPrecio() const{
    return this->precio;
}
double Envio::calculaCosto(){
    return this->precio;
}
void Envio::setPrecio(double precio_){
    this->precio = precio_;
}
void Envio::setReceptor(Persona receptor_){
    this->receptor = receptor_;
}
void Envio::setRemitente(Persona remitente_){
    this->receptor = remitente_;
}
void Envio::imprime(){
    cout << "Mi precio es " << this->precio << endl;
    cout << "Mi remitente es " << this->remitente.getNombre() << endl;
    cout << "Mi receptor es " << this->receptor.getNombre() << endl;
}