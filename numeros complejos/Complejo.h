#ifndef COMPLEJO_H_ 
#define COMPLEJO_H_ 
#include <iostream>
using namespace std;
class Complejo { 
    public: 
        // constructores 
        Complejo(); 
        Complejo(double real, double imagi); 
        // método 
        void imprime(); 
        void agregar(Complejo& complex);
        Complejo conjugado();
        Complejo suma(Complejo& complex);
        Complejo multiplicacion(Complejo& complex);
        Complejo multiEscalar(double esca);
        // métodos de modificación 
        void setReal(double real); 
        void setImaginario(double imagi); 
        // métodos de acceso 
        double getReal(); 
        double getImaginario(); 
        
    private: 
    // atributos 
        double REAL, IMAGI; 
}; 
#endif

