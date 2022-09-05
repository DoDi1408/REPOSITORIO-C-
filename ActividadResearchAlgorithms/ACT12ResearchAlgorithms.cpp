using namespace std;
#include <iostream>
#include <vector> 
#include <algorithm>
// A01635547 RODRIGO ALEJANDRO CHAVEZ AVALOS
// 15/08/22
// mergesort de algoexpert.io

// O(n^2)
void insertionSort(vector <int>& arrayIS){
    int j, key;
    for (int i=1;i<arrayIS.size()-1;i++){
        key = arrayIS[i];
        j = i - 1;
        while (j >= 0 && arrayIS[j] > key){
            swap(arrayIS[j+1],arrayIS[j]);
            j = j - 1;
        }
    }
}
// O(n^2)
void bubbleSort(vector <int>& arrayBS){
    for (int j=0;j<arrayBS.size()-1;j++){
        for (int i=0;i<arrayBS.size()-1-j;i++){
            if (arrayBS[i] > arrayBS[i+1]){
                swap(arrayBS[i],arrayBS[i+1]);
            }
        }
    }
}
// Complexity Level n Log(n)
vector <int> mergeSortedArrays(vector<int> mitadIzq, vector<int> mitadDer){
    vector<int> sortedArray(mitadIzq.size() + mitadDer.size(), 0);
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < mitadIzq.size() && j < mitadDer.size() ){
        if(mitadIzq[i] <= mitadDer[j]){
            sortedArray[k] = mitadIzq[i];
            k++;
            i++;
        }
        else {
            sortedArray[k] = mitadDer[j];
            k++;
            j++;
        }
    }
    while (i < mitadIzq.size()){
        sortedArray[k] = mitadIzq[i];
        k++;
        i++;
    }
    while (j < mitadDer.size()){
        sortedArray[k] = mitadDer[j];
        k++;
        j++;
    }
    return sortedArray;
}
// Complexity Level n Log(n)
vector<int> mergeSort(vector <int> arrayMS){
    if (arrayMS.size() <= 1){
        return arrayMS;
    }
    int mid = arrayMS.size() /2;
    vector<int> mitadIzq(arrayMS.begin(), arrayMS.begin() + mid);
    vector<int> mitadDer(arrayMS.begin() + mid, arrayMS.end());
    return mergeSortedArrays(mergeSort(mitadIzq), mergeSort(mitadDer));
}
// o(n)
int sequentialSearch(vector <int> vectorS, int target){
    for (int i=0;i<vectorS.size();i++){
        if (target == vectorS[i]){
            return i;
        }
    }
    return -1;
}
//  o log(n)
int binarySearch(vector <int> vectorB, int target){
    int leftP = 0;
    int rightP = vectorB.size() -1;
    int mid = rightP - leftP;
    while (leftP <= rightP){
        int mid = (rightP + leftP)/2;
        if (vectorB[mid] == target){
            return mid;
        }
        else if (vectorB[mid] > target){
            rightP = mid - 1;
        }
        else {
            leftP = mid + 1;
        }
    }
    return -1;
}
int main(){
    int numeroBusquedas;
    vector <int> numeros;
    vector <int> g2 = {4,2,1,3,5};
    vector <int> g3 = (mergeSort(g2));
    cout << "Enter the number of searches you want " << endl;
    cin >> numeroBusquedas;
    for (int i=1;i<=numeroBusquedas;i++){
        cout << "Now enter the number you want to search on search number " << i << ": ";
        int numeroLoop;
        cin >> numeroLoop;
        numeros.push_back(numeroLoop);
    }
    for (int i=1;i<=numeroBusquedas;i++){
        cout << "For search number " << i << ", you selected number " << numeros[i-1] << ", below are the results" << endl;
        cout << "Index(sequentialSearch) = " << sequentialSearch(g3,numeros[i-1]) << endl;
        cout << "Index(binarySearch) = " << binarySearch(g3,numeros[i-1]) << endl;
    }
    return 0;
}