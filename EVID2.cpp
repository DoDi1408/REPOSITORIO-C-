//Erick Daniel Luna Carrada A01635367
//Ricardo Jimenez Ureña A01636825
#include <vector>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>

using namespace std;

void createVector(vector<string>&v){
    ifstream file;
    file.open("bitacora.txt");
    string line;

    if(!file.is_open()){
        cout << "No se abrió" << endl;
    }else{
        while (getline(file, line)){
            v.push_back(line);
        }
    }
}

bool vectorCheck(vector<int>&vec1, vector<int>&vec2){
    for(int i = 0; i <= 3; i++){
        if(vec1[i] < vec2[i]){
            return true;
        }
        else if(vec1[i] > vec2[i]){
            return false;
        }
    }

}

bool vectorEqual(vector<int>&vec1, vector<int>&vec2){
    for(int i = 0; i <= 3; i++){
        if(vec1[i] < vec2[i]){
            return false;
        }
    }
    return true;
}

vector<int> valueIP(vector<string>&v, int i){
        istringstream iss;
        string month, day, hour, ip, num_str;
        int cont = 0, start = 0;
    
        iss.str(v[i]);
        iss >> month >> day >> hour >> ip;

        vector<int>vec;   
        while(cont <= ip.length()){
            if(ip[cont] == '.' || ip[cont] == ':'){
                num_str = ip.substr(start,cont);
                start = cont + 1;
                vec.push_back(stoi(num_str));
            }
            cont++;
        }
        return vec; 

}

int partition(vector<string>&v, int start, int end){
    vector<int> pivote = valueIP(v, start);
    int i = start + 1;
    for(int j = i; j <= end; j++){
        vector<int> pivote2 = valueIP(v, j);
        if(vectorCheck(pivote2, pivote)){
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[start], v[i-1]);
    return i-1;
}

void quickSort(vector<string>&v, int start, int end){
    if(start < end){
        int pivote = partition(v, start, end);
        quickSort(v, start, pivote-1);
        quickSort(v, pivote+1,end);
    }
}

void printVector(vector<string>&v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

void createTxt(vector<string>&v){
    ofstream out_file("sort_bitacora.txt");

    ostream_iterator<string> out_iterator(out_file, "\n");
    copy(v.begin(),v.end(), out_iterator);
}

int binarySearch(vector<string>&v, vector<int>&vec){
    int min, sup, mid;
    min = 0;
    sup = v.size()-1;
    vector<int> ipComp;

    while(min <= sup){
        mid = ((sup-min)/2)+min;
        vector<int> ipComp = valueIP(v, mid);
        
        if(vectorCheck(vec, ipComp)){
            sup = mid - 1;
        }
        else if(vectorCheck(ipComp, vec)){
            min = mid + 1;
        }
        else{
            break;
        }
    }

    while (vectorEqual(vec, ipComp)){
        mid --;
        if(mid == 1){
            return mid;
        }
    }
    
    if (vectorEqual(vec, ipComp) == false){
        return mid + 2;
    }
    
    return -1;
}

int main(){
    vector<string> v;
    int n, res, res1;

    createVector(v);
    quickSort(v,0,v.size()-1);
    createTxt(v);

    vector<int> v1;
    vector<int> v2;

    cout << "\n---------------------------- DATA BASE ----------------------------" << endl;
    cout << "Denied entries history..." << endl;
    cout << "Searching for the IP history..." << endl << endl;
    cout << "" << endl << endl;
    cout << "Enter INITIAL IP (4 digit numbers): " << endl;
    for(int i = 0; i < 4; i++){
        cout << "Enter digit " << "(" <<i +1 << ")  =  ";
        cin >> n; 
        v1.push_back(n); 
    }

    cout << "\nEnter INITIAL IP (4 digit numbers): " << endl;
    for(int i = 0; i < 4; i++){
        cout << "Enter digit " << "(" <<i +1 << ")  =  ";
        cin >> n; 
        v2.push_back(n); 
    }

    res = binarySearch(v, v1);
    res1 = binarySearch(v, v2);

    cout << res << endl;

    for(int i = res; i < res1-1; i++){
        cout << v[i] << endl;
    }

    return 0;
}
