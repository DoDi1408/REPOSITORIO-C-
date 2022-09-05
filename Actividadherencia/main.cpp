#include "Sobre.h"
#include "Paquete.h"
#include <iostream>
using namespace std;

int main(){
    Persona p1 ("Diego", "Guadalajara", 43912);
    p1.imprime();
    Persona p2 ("Rodrigo", "Tepic", 12345);
    p2.imprime();
    Envio e1 (p1,p2);
    e1.imprime();
    // resultado esperado 100 porque eso es mi precio estandar
    cout << e1.calculaCosto() <<endl;
    Paquete pa1 (p1, p2, 10, 10, 10, 5, 1.5);
    pa1.imprime();
    // esperaria que fuera mas porque el peso es de 5 kg y por cada kg le cobro 1.5 pesos mas.
    cout << pa1.calculaCosto() <<endl;
    Sobre s1 (p1,p2,30,35);
    s1.imprime();
    // deberia de ser mas de 100
    cout << s1.calculaCosto() <<endl;
return 0; 
}