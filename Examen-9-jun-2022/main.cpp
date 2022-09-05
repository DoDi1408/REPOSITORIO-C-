// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#include "Pixel.h"
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <Punto*> puntos;
    puntos.push_back(new Punto(5,7));
    puntos.push_back(new Punto3d(9,1,3));
    puntos.push_back(new Punto3d(8,3,12));
    puntos.push_back(new Pixel(35,21, "3bd0a8"));
    puntos.push_back(new Pixel(15,20, "3b19bb"));
    for (int i=0; i<puntos.size();i++){
        cout << puntos[i] << endl;
    }
    return 0;
}