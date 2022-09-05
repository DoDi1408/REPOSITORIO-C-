#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;
class Persona{
    public:
        Persona();
        Persona(string, string, int);
        string getNombre() const;
        string getCiudad() const;
        int getCodigoPostal() const;
        void setNombre(string);
        void setCiudad(string);
        void setCodigoPostal(int);
        void imprime();
    private:
        string nombre, ciudad;
        int codigoPostal;
};
#endif