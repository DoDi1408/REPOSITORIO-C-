//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include "Serie.h"

Serie::Serie(){
    this->numTemporadas = 0;
}

Serie::Serie(int numTemporadas, int id, int numRatings, double ratingTotal, std::string nombre, std::string genero):Video(id, numRatings, ratingTotal, nombre, genero){
    this->numTemporadas = numTemporadas;
}
int Serie::getNumTemporadas(){
    return this->numTemporadas;
}
void Serie::setNumTemporadas(int numTemporadas){
    this->numTemporadas = numTemporadas;
}
std::vector<Episodio> Serie::getEpisodios(){
    return this->episodios;
}
void Serie::imprimir(){
    std::cout << "------------------------------------------------------------------" << std::endl;
    Video::imprimir();
    std::cout << "  TEMPORADAS: " << this->numTemporadas << std::endl;
    std::cout << std::endl;
    std::cout << "EPISODIOS:" << std::endl;
    for (auto &episodio : this->episodios){  
        std::cout << std::endl;
        episodio.imprimir();
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
    
}

void Serie::agregarEpisodio(Episodio& episodio){
    this->episodios.push_back(episodio);
}

bool Serie::calificarEpisodio(int id, double rating){
    for(auto &episodio : this->episodios){
        if(episodio.getId() == id){
            episodio + rating;
            return true;
        }
    }
    return false;
}