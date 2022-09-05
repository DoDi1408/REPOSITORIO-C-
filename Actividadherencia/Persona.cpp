#include "Persona.h"
#include <iostream>
using namespace std;
Persona::Persona(){
    this->nombre = "Juan";
    this->ciudad = "Guadalajara";
    this->codigoPostal = 45645;
}
Persona::Persona(string nombre_, string ciudad_, int codigoPostal_){
    this->nombre = nombre_;
    this->ciudad = ciudad_;
    this->codigoPostal = codigoPostal_;
}
string Persona::getNombre() const{
    return this->nombre;
}
string Persona::getCiudad() const{
    return this->ciudad;
}
int Persona::getCodigoPostal() const{
    return this->codigoPostal;
}
void Persona::setNombre(string nombre_){
    this->nombre = nombre_;
}
void Persona::setCiudad(string ciudad_){
    this->ciudad = ciudad_;
}
void Persona::setCodigoPostal(int codigoPostal_){
    this->codigoPostal = codigoPostal_;
}
void Persona::imprime(){
    cout << "Mi nombre es " << this->nombre << endl;
    cout << "Vivo en " << this->ciudad << endl;
    cout << "Mi codigo postal es " << this->codigoPostal << endl;
}