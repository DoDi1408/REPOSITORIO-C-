 #include "Complejo.h"
 #include <iostream>
 int main(){
    Complejo comp(5,5);
    Complejo test;
    cout << comp.getReal() <<endl;
    comp.imprime();
    test = comp.multiEscalar(3);
    test.imprime();
    return 0;
 }