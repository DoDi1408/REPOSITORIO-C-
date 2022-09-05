using namespace std;
#include <iostream>
// A01635547 RODRIGO ALEJANDRO CHAVEZ AVALOS
// 15/08/22



// sum from 1 to n using iteration
// Complexity of O(n); linear
int sumIterative(int n){
    int suma;
    if (n <= 0) return 0;
    // iterative for loop
    for (int i=1;i<=n;i++){
        suma += i;
    }
    return suma-1;
}
// complexity of O(1); constant
// sum from 1 to n using a direct mathematical formula
int directSum(int n){
    int suma;
    if (n <= 0) return 0;
    // direct mathematical formula for 1 to n
    suma = (n*(n+1))/2;
    return suma;
}
// complexity of O(n), linear
// sum from 1 to n using recursion
int recursiveSum(int n){
    int suma;
    // base step
    if (n <= 1) return 1;
    return n + recursiveSum(n-1);
}
int main(){
    cout << sumIterative(35) << endl;
    cout << directSum(35) << endl;
    cout << recursiveSum(35) << endl;
    return 0;
}