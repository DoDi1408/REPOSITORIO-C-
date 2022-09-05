//Mateo Bernasconi Vargas A01635675
//Rodrigo Chavez Avalos A01635547
#include <iostream>
#include <string>
#include <vector>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Catalogo.h"

using namespace std;

int main(){
    //Llenar catalogo
    Catalogo c1("contenido.txt");
    //Menu
    cout << "Bienvenido a la mejor plataforma de streaming!!" << endl;
    cout << endl;
    string opcionMenu;
    while(opcionMenu != "0"){
        cout << endl;
        cout << "Eliga una opción:" << endl;
        cout << "1) Para ver el catalogo completo" << endl;
        cout << "2) Para ver el catalogo filtrado por serie o pelicula" << endl;
        cout << "3) Para ver el catalogo filtrado por rating minimo" << endl;
        cout << "4) Para ver el catalogo filtrado por genero" << endl;
        cout << "5) Para ver los episodios de una serie filtrado por rating" << endl;
        cout << "6) Para buscar una serie o pelicula por nombre" << endl;
        cout << "7) Para calificar una pelicula, serie o episodio" << endl;
        cout << "0) Para salir" << endl;
        cin >> opcionMenu;
        cout << endl;
        if(opcionMenu == "1"){
            //Imprimir catalogo completo
            c1.imprimir();
        }else if(opcionMenu == "2"){
            //Eligir filtro por serie o pelicula
            string tipoVideo;
            while(tipoVideo != "regresar" && tipoVideo != "serie" && tipoVideo != "pelicula"){
                cout << "Elige un filtro valido porfavor:" << endl;
                cout << "serie" << endl;
                cout << "pelicula" << endl;
                cout << "regresar" << endl;
                cin >> tipoVideo;
            }   
            if(tipoVideo != "regresar"){
                c1.filtarTipoVideo(tipoVideo);
            }
        }else if(opcionMenu == "3"){
            //Eligir rating minimo para filtro
            string rating;
            try{
                cout << "Elige un rating entre 1-5 o ingrese 'regresar' para ir al menu principal"  << endl;
                cin >> rating;
                if(stod(rating) < 1 || stod(rating) > 5){
                    string mensaje = rating + " es un rating invalido";
                    throw invalid_argument(mensaje);
                }
                c1.filtrarRating(stod(rating));
            }catch(invalid_argument &ex){
                cout << "Número invalido: " << ex.what() << endl;
            }

        }else if(opcionMenu == "4"){
            //Eligir genero para filtro
            string genero;
            cout << "Escriba el genero por el cual le gustaría filtrar"  << endl;
            cin >> genero;
            c1.filtrarTipoGenero(genero);

        }else if(opcionMenu == "5"){
            //Filtrar episodios de una serie por rating 
            string id, rating;
            try{
                cout << "Escriba el id de la serie que le gustaría filtrar"  << endl;
                cin >> id;
                cout << endl;
                cout << "Escriba el rating minimo de 1-5 que le gustaría usar para filtrar los episodios"  << endl;
                cin >> rating;
                if(stod(rating) < 1 || stod(rating) > 5){
                    string mensaje = rating + " es un rating invalido";
                    throw invalid_argument(mensaje);
                }
                c1.filtrarRatingEpisodios(stoi(id), stod(rating));
            }catch(invalid_argument &ex){
                cout << "ID o rating invalido: " << ex.what() << endl;
            }

        }else if(opcionMenu == "6"){
            //Buscar un video por nombre
            string nombre;
            cout << "Escriba nombre de la serie o pelicula porfavor"  << endl;
            cin >> nombre;
            c1.filtrarVideoNombre(nombre);

        }else if(opcionMenu == "7"){
            //Calificar una serie, pelicula o episodio
            string id, rating;
            
            

        }else if(opcionMenu != "0"){
            cout << "Opción invalida, vuelva a intentar" << endl;
        }
    }

}