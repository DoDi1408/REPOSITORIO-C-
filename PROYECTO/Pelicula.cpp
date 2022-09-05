//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include "Pelicula.h"

Pelicula::Pelicula(){
    this->duracion = 0;
}

Pelicula::Pelicula(int duracion,int id, int numRatings, double ratingTotal, std::string nombre, std::string genero):Video(id, numRatings, ratingTotal, nombre, genero){
    this->duracion = duracion;
}

void Pelicula::imprimir(){
    std::cout << "------------------------------------------------------------------" << std::endl;
    Video::imprimir();
    std::cout << "  DURACION: " << this->duracion << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
}

int Pelicula::getDuracion(){
    return this->duracion;
}

void Pelicula::setDuracion(int duracion){
    this->duracion=duracion;
}