#ifndef ENVIO_H
#define ENVIO_H
#include <string>
#include "Persona.h"
using namespace std;
class Envio{
    public:
        Envio();
        Envio(Persona&, Persona&);
        Persona getRemitente() const;
        Persona getReceptor() const ;
        double getPrecio() const;
        double calculaCosto();
        void setPrecio(double);
        void setRemitente(Persona);
        void setReceptor(Persona);
        void imprime();
    private:
        Persona remitente, receptor;
        double precio;
};
#endif