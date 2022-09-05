//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"
#include <iostream>
#include <vector> 

class Serie:public Video{
    public:
        //contructores
        Serie();
        Serie(int numTemporadas, int id, int numRatings, double ratingTotal, std::string nombre, std::string genero);

        //Getters y setters
        int getNumTemporadas();
        void setNumTemporadas(int);
        std::vector<Episodio> getEpisodios();
        void agregarEpisodio(Episodio&);

        //Función polimorfica
        void imprimir() override;

        //calificar episodio
        bool calificarEpisodio(int id, double rating);
    private:
        int numTemporadas;
        std::vector<Episodio> episodios; 

};
#endif // SERIE_H