//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include "Video.h"

Video::Video(){
    this->id = 123456;
    this->numRatings = 0;
    this->ratingTotal = 0;
    this->nombre = "deafult";
    this->genero = "deafult";
}

Video::Video(int id,int numRatings, double ratingTotal, std::string nombre, std::string genero){
    this->id = id;
    this->numRatings = numRatings;
    this->ratingTotal = ratingTotal;
    this->nombre = nombre;
    this->genero = genero;
}

void Video::operator +(double rating){
    this->numRatings++;
    this->ratingTotal += rating;
}

void Video::imprimir(){
    std::cout << "ID: " << this->id << "  NOMBRE: " << this->nombre << std::endl;
    std::cout << "CALIFICACION: " << this->ratingTotal/this->numRatings << "  GENERO: " << this->genero;
}

int Video::getId(){
    return this->id;
}
int Video::getNumRatings(){
    return this->numRatings;
}
double Video::getRatingTotal(){
    return this->ratingTotal;
}
std::string Video::getNombre(){
    return this->nombre;
}
std::string Video::getGenero(){
    return this->genero;
}

void Video::setId(int id){
    this->id = id;
}

void Video::setNumRatings(int numRatings){
    this->numRatings = numRatings;
}

void Video::setRatingTotal(double ratingTotal){
    this->ratingTotal = ratingTotal;
}

void Video::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Video::setGenero(std::string genero){
    this->genero = genero;
}
