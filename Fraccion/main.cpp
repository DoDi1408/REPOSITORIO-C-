 //Realiza el main para probar todos los operadores
 // A01635547 RODRIGO ALEJANDRO CHAVEZ AVALOS
#include "ArrayFracc.h"
#include <fstream>
#include <string>
using namespace std;

void cargaDatos(ArrayFracc& misFracciones){
    ifstream archivo;
    char fraccion; 
    int num;
    int den;
    archivo.open("datosFracciones.txt");
    if (archivo.is_open()){
        while (archivo >> fraccion) {
            if (fraccion == 'f' ){
                archivo >> num >> den;
                Fraccion f(num, den);
                misFracciones.agregaFraccion(f);
            }
            else{
                break;
            }
        }
    }
    //Llena con esta función los datos del objeto misFracciones
    //con la lectura de un archivo de texto
}
//Puedes crear más funciones si las requieres...
//Llena la función principal para hacer todas tus pruebas
int main(){
    Fraccion f1;
    Fraccion f2;
    //Crea dos fracciones con datos que recibas del usuario
    cout << "Vamos a crear 2 fracciones, recuerda que tienen que poder existir" << endl;
    cout << "Mete los datos con el orden numerador denominador, separados por un espacio:  ";
    cin >> f1;
    cout << endl <<"Ahora la segunda: ";
    cin >> f2;
    int loop=1;
    //Prueba los distintos operadores de la clase Fracción haz un menu para
    //que el usuario decida qué operación quiere realizar con estas dos fracciones
    while (loop != 0){
        cout << "Que quieres hacer con estas 2 fracciones? (Escribe lo que esta en parentesis)" << endl;
        cout << "suma (+)" << endl << "resta(-)" << endl << "igual (=)" << endl << "Fraccion 1 es mas grande que la 2? (1) "<< endl << "Fraccion 2 es mas grande que la 1? (2)" <<endl;
            char operador;
            cin >> operador;
        switch(operador){
            case '+':
                cout << "El resultado de la suma es: " <<  f1 + f2 << endl;
                break;
            case '-':
                cout << "El resultado de la resta es: " <<  f1 - f2 << endl;
                break;
            case '1':
                cout << "Es la primera fraccion mas grande que las segunda: " ;
                if (f1>f2){
                    cout << "si" << endl;
                }
                else{
                    cout << "no" << endl;
                }
                break;
            case '2':
                cout << "Es la segunda fraccion mas grande que las primera: " ;
                if (f2>f1){
                    cout << "si" << endl;
                }
                else {
                    cout << "no" << endl;
                }
                break;
            case '=':
                cout << "Son iguales?: " ;
                if (f2==f1){
                    cout << "si" << endl;
                }
                else {
                    cout << "no" << endl;
                }
                break;
            default:
                cout << "Has ingresado un caracter no valido, intentalo mas tarde" << endl;
                break;
        }
        cout << "Si quieres seguir ingresa cualquier numero excepto cero:  ";
        cin >> loop;
        cout << endl;
    }
    //llena los datos de un ArrayFracc y prueba el operador de indexación
    cout << "Aqui estan mis fracciones de el text file" << endl;
    ArrayFracc misFracciones;
    cargaDatos(misFracciones);
    cout << "Fraccion 1 de mi lista: " << misFracciones[0] << endl;
    cout << "Fraccion 2 de mi lista: " << misFracciones[1] << endl;
    cout << "Fraccion 3 de mi lista: " << misFracciones[2] << endl;
    return 0;
}