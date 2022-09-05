//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream>

class Episodio{
    public:
        // constructor
        Episodio();
        Episodio(std::string titulo, int id, int numTemporada,int numEpisodio, int numRatings, double ratingTotal);
        // sobrecarga
        void operator+(double);
        // getters 
        std::string getTitulo() const;
        int getId() const;
        int getNumTemporada() const;
        int getNumEpisodio() const;
        int getNumRatings() const;
        double getDuracion() const;
        double getRatingTotal() const;
        // setters
        void setTitulo(std::string);
        void setId(int);
        void setNumTemporada(int);
        void setNumEpisodio(int);
        void setNumRatings(int);
        void setRatingTotal(double);
        
        void imprimir();
    private:
        std::string titulo;
        int id;
        int numTemporada;
        int numEpisodio;
        int numRatings;
        double ratingTotal;
};
#endif