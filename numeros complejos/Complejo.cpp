 #include "Complejo.h"
 #include <iostream>
using namespace std;
Complejo::Complejo(){
    REAL=0;
    IMAGI=0;
}
Complejo::Complejo(double real, double imagi){
    REAL=real;
    IMAGI=imagi;
}
void Complejo::imprime(){
    if (this->IMAGI < 0){
        cout << "(" << this->REAL << " " << this->IMAGI << "i)" << "\n";
    }
    else{
        cout << "(" << this->REAL << " + " << this->IMAGI << "i)" << "\n";
    }
}
double Complejo::getReal(){
    return REAL;
}
double Complejo::getImaginario(){
    return IMAGI;
}
void Complejo::setImaginario(double imagi){
    IMAGI = imagi;
}
void Complejo::setReal(double real){
    REAL = real;
}
void Complejo::agregar(Complejo& complex){
    this->REAL = this->REAL + complex.getReal();
    this->IMAGI = this->IMAGI + complex.getImaginario();
}
Complejo Complejo::conjugado(){
    double x,
           y;
    x=this->REAL;
    y=this->IMAGI*-1;
    return Complejo(x,y);
}
Complejo Complejo::suma(Complejo& complex){
    double rial,
           imaji;
    rial = this->REAL + complex.getReal();
    imaji = this->IMAGI + complex.getImaginario();
    return Complejo(rial,imaji);
}
Complejo Complejo::multiplicacion(Complejo& complex){
    double rial,
           imaji;
    rial = (this->REAL * complex.getReal()) - (this->IMAGI * complex.getImaginario());
    imaji = (this->REAL * complex.getImaginario()) + (this->IMAGI * complex.getReal());
    return Complejo(rial,imaji);
}
Complejo Complejo::multiEscalar(double esca){
    double rial,
           imaji;
    rial = this->REAL * esca;
    imaji = this->IMAGI * esca;
    return Complejo(rial,imaji);
}

