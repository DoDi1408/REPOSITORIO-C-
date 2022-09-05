//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include <iostream>
#include "Episodio.h"

Episodio::Episodio(){
    this->titulo = "default";
    this->id = 123456;
    this->numTemporada = 1;
    this->numEpisodio = 1;
    this->numRatings = 1;
    this->ratingTotal = 5;
}
Episodio::Episodio(std::string titulo, int id, int numTemporada,int numEpisodio, int numRatings, double ratingTotal){
    this->titulo = titulo;
    this->id = id;
    this->numTemporada = numTemporada;
    this->numEpisodio = numEpisodio;
    this->numRatings = numRatings;
    this->ratingTotal = ratingTotal;
}
void Episodio::operator+(double review){
    this->ratingTotal += review;
    this->numRatings++;
}

std::string Episodio::getTitulo() const{
    return this->titulo;
}
int Episodio::getId() const{
    return this->id;
}
int Episodio::getNumTemporada() const{
    return this->numTemporada;
}
int Episodio::getNumEpisodio() const{
    return this->numEpisodio;
}
int Episodio::getNumRatings() const{
    return this->numRatings;
}
double Episodio::getRatingTotal() const{
    return this->ratingTotal;
}

void Episodio::setTitulo(std::string titulo){
    this->titulo = titulo;
}
void Episodio::setId(int id){
    this->id = id;
}
void Episodio::setNumTemporada(int numTemporada){
    this->numTemporada = numTemporada;
}
void Episodio::setNumEpisodio(int numEpisodio){
    this->numEpisodio = numEpisodio;
}
void Episodio::setNumRatings(int numRatings){
    this->numRatings = numRatings;
}
void Episodio::setRatingTotal(double){
    this->ratingTotal = ratingTotal;
}
void Episodio::imprimir(){
    std::cout << "   ID: " << this->id << "  NOMBRE: " << titulo << std::endl;
    std::cout << "   EPISODIO: " << this->numEpisodio << "  TEMPORADA: " << numTemporada << std::endl;
    std::cout << "   CALIFICACION: " << this->ratingTotal/this->numRatings << std::endl;
}