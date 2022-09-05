#ifndef PAQUETE_H
#define PAQUETE_H
#include <string>
#include "Envio.h"
using namespace std;
class Paquete:public Envio{
    public:
        Paquete();
        Paquete(Persona&, Persona&, double, double, double, double, double);
        double calculaCosto();
        double getLargo() const;
        double getAncho() const;
        double getProfundidad() const;
        double getPeso() const;
        double getPesoKg() const;
        void setLargo(double);
        void setAncho(double);
        void setProfundida(double);
        void setPeso(double);
        void setPesoKg(double);
        void imprime();
    private:
        double largo, ancho, profundidad, peso, pesoKg;
};
#endif