//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include "Catalogo.h"

Catalogo::Catalogo(std::string nombreArchivoTexto){
    std::string nombre, titulo, genero;
    int id, numTemporada, numRatings, numEpisodio, duracion;
    double ratingTotal;
    //Vector para guardar los episodios temporalmente
    std::vector<Episodio> epTemp; 
        
    //Lectura de txt
    std::ifstream archivo;
    archivo.open(nombreArchivoTexto);
    char tipoVideo;
    if (archivo.is_open()){
        while (archivo >> tipoVideo) {
            if (tipoVideo == 'P' ) {
                //Peliculas
                archivo >> duracion >> id >> numRatings >> ratingTotal >> nombre >> genero; 
                this->contenido.push_back(new Pelicula(duracion, id, numRatings, ratingTotal, nombre, genero));
            }else if(tipoVideo == 'S'){
                //Series
                archivo >> numTemporada >> id >> numRatings >> ratingTotal >> titulo >> genero;
                Serie *serie;
                serie = new Serie(numTemporada, id, numRatings, ratingTotal, titulo, genero);

                for (int i=0; i< epTemp.size(); i++){
                    serie->agregarEpisodio(epTemp[i]);
                }
                this->contenido.push_back(serie);
                epTemp.clear();
            }else if(tipoVideo == 'E'){
                //episodios
                archivo >> nombre >> id >> numTemporada >> numEpisodio >> numRatings >> ratingTotal;
                Episodio ep(nombre, id, numTemporada, numEpisodio, numRatings, ratingTotal);
                epTemp.push_back(ep);
            }
        }
    }
    archivo.close();
}

//Imprimir todo el catalogo
void Catalogo::imprimir(){
    for (auto &video : this->contenido){
        video->imprimir();
    }
}

//Filtrar catalogo por pelicula o serie
void Catalogo::filtarTipoVideo(std::string tipo){
    for (auto &video : this->contenido){
        //Checar si video es serie o pelicula
        std::string tipoVideo;
        if(Pelicula* ptrPelicula=dynamic_cast<Pelicula *>(video)){
            tipoVideo = "pelicula";
        }else if(Serie* ptrSerie=dynamic_cast<Serie *>(video)){
            tipoVideo = "serie";
        }
        //En caso de cumplir con el filtro
        if(tipo == "pelicula" && tipoVideo == "pelicula"){
            video->imprimir();
        }else if(tipo == "serie" && tipoVideo == "serie"){
            video->imprimir();
        }
    }
}

//Filtrar catalogo por genero
void Catalogo::filtrarTipoGenero(std::string genero){
    bool encontrado = false;
    for (auto &video : this->contenido){
        if(video->getGenero() == genero){
            video->imprimir();
            encontrado = true;
        }
    }

    //En caso de no encontrar video con genero introducido
    if(encontrado == false){
        std::cout << "No se encontro ningun resultado para su filtro" << std::endl;
    }

}

//Filtrar catalogo por rating
void Catalogo::filtrarRating(double rating){
    bool encontrado = false;
    for (auto &video : this->contenido){
        if(video->getRatingTotal() / video->getNumRatings() >= rating){
                video->imprimir();
                encontrado = true;
            }
    }

    //En caso de no encontrar video con rating minimo introducido
    if(encontrado == false){
        std::cout << "No se encontro ningun resultado para su filtro" << std::endl;
    }
}

//Filtrar episodios de una serie por rating
void Catalogo::filtrarRatingEpisodios(int id, double rating){
    bool encontrado = false;
    for (auto &video : this->contenido){
        if(Serie* ptrSerie=dynamic_cast<Serie *>(video)){
            if(ptrSerie->getId() == id){
                std::vector<Episodio> episodios = ptrSerie->getEpisodios();
                for(int i = 0; i < episodios.size(); i++){
                    if(episodios[i].getRatingTotal() / episodios[i].getNumRatings() >= rating){
                        episodios[i].imprimir();
                        std::cout << std::endl;
                        encontrado = true;
                    }
                }
            }
        }
        
    }

    //En caso de no encontrar episodio con rating minimo introducido
    if(encontrado == false){
        std::cout << "No se encontro ningun episodio para su rating mínimo" << std::endl;
    }
}

//Busqueda de serie o pelicula por nombre
void Catalogo::filtrarVideoNombre(std::string nombre){
    bool encontrado = false;
    for (auto &video : this->contenido){
        if(video->getNombre() == nombre){
            video->imprimir();
            encontrado = true;
        }
    } 

    //En caso de no encontrar video por nombre introducido
    if(encontrado == false){
        std::cout << "No se encontro ningun resultado para su busqueda" << std::endl;
    }
}

//Calificar serie, episodio o pelicula
void Catalogo::calificarVideo(int id, double rating){ 
    bool encontrado = false;
    for (auto &video : this->contenido){
        if(video->getId() == id){
            *video + rating;
            encontrado = true;
            return;
        }else if(Serie* ptrSerie=dynamic_cast<Serie *>(video)){
            encontrado = ptrSerie->calificarEpisodio(id, rating);
        }
    } 

    //En caso de no encontrar video por id introducido
    if(encontrado == false){
        std::cout << "No se encontro ningun video con el id introducido" << std::endl;
    }
}
