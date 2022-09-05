#include <iostream>
#include "CoordRect.h"
#include "CoordPolar.h"
using namespace std;

int main(){
    CoordRect c1(2,3);
    CoordRect c2(4,7);
    CoordPolar p1(4,20);
    CoordRect suma=c1+c2;
    CoordRect suma2=c1+p1;
    cout << suma << endl;
    cout << suma2 << endl;
    return 0;
}