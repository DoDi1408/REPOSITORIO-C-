//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

class Video{
    public:
        //constructores
        Video();
        Video(int id,int numRatings, double ratingTotal, std::string nombre, std::string genero);
        //clase abstracta pura
        virtual void imprimir() = 0;

        //sobrecarga de +
        void operator +(double);

        //getters
        int getId();
        int getNumRatings();
        double getRatingTotal();
        std::string getNombre();
        std::string getGenero();

        //setters
        void setId(int);
        void setNumRatings(int);
        void setRatingTotal(double);
        void setNombre(std::string);
        void setGenero(std::string);

    private:
        int id;
        int numRatings;
        double ratingTotal;
        std::string nombre;
        std::string genero; 
};
#endif // VIDEO_H