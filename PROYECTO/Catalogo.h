//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#ifndef CATALOGO_H
#define CATALOGO_H
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

class Catalogo{
    
    public:
        //Constructor
        Catalogo(std::string nombreArchivoTexto);

        //Funciones usadas por el usuario
        void imprimir();
        void filtarTipoVideo(std::string tipo);
        void filtrarTipoGenero(std::string genero);
        void filtrarRating(double rating);
        void filtrarRatingEpisodios(int id, double rating);
        void filtrarVideoNombre(std::string nombre);
        void calificarVideo(int id, double rating);
    private:
        std::vector<Video*> contenido; 
        
        
};
#endif //CATALOGO_H