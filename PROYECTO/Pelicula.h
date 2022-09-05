//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

class Pelicula:public Video{
    public:
        //Constructores
        Pelicula();
        Pelicula(int duracion, int id, int numRatings, double ratingTotal, std::string nombre, std::string genero);

        //Función polimorfica 
        void imprimir() override;

        //getters y setters
        int getDuracion();
        void setDuracion(int);
    private:
        int duracion;
};
#endif // PELICULA_H








