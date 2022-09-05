using namespace std;
#include <iostream>

int fibon(int i){
    cout << "Entering to compute f: " << i << endl;
    // base step
    if (i <= 2) return 1;
    return fibon(i-1) + fibon(i-2);
}
int fac(int n){
    if(n <= 0) return 1;
    return n * fac(n-1);
}
int main(){
    cout << fibon(8) << endl;
    cout << "Now calculating factorial" << endl;
    cout << fac(6) << endl;
    return 0;
}