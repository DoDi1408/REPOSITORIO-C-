#ifndef SOBRE_H
#define SOBRE_H
#include <string>
#include "Envio.h"
using namespace std;
class Sobre:public Envio{
    public:
        Sobre();
        Sobre(Persona&, Persona&, double, double);
        double calculaCosto();
        double getLargo() const;
        double getAncho() const;
        void setLargo(double);
        void setAncho(double);
        void imprime();
    private:
        double largo, 
               ancho;
};
#endif