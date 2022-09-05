#include <iostream>
using namespace std;

int main() {
    double* pvalue = NULL; // pointer initialized with null
    pvalue = new double; // request memory for the variable

    *pvalue = 29494.99; // store value at allocated adress
    cout << "Value of pvalue : " << *pvalue << endl;
    cout << "pvalue stored at: " << pvalue << endl;

    delete pvalue; //free up the memory
    return 0;

    //create an array of pointers that points to more arrays
    int** matrix = new int*[5];
    for (int i = 0; i < 5; ++i){
        matrix [i] = new int [5];
        for ( int j = 0; j < 5; ++j){
            matrix [i][j] = i*5 + j;
        }
    }
    // free each subarray
    for (int i = 0; i < 5; ++i){
        delete[] matrix[i];
    }
    //free the array of pointers
    delete[] matrix;
}