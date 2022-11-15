#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string> 
#include <sstream>
#include <limits.h>

using namespace std;

struct Node {
    int key;
    string ip;
    Node(int key, string ip):key(key), ip(ip){}
};
// O(n)
unordered_map<string,int> fillHash(){

    istringstream iss;
    ifstream file;
    string line, month, day, hour, ip, num_str;
    unordered_map<string,int> output;
    file.open("bitacora.txt");
    while (getline(file, line)){
            iss.str(line);
            iss >> month >> day >> hour >> ip;
            num_str = ip.substr(0,13);
            output[num_str] += 1;
    }
    return output;
}

class priorityQueue{
    private:
        vector<Node> heapTree;
        int parent(int);
        int lChild(int);
        int rChild(int);
    public:
        priorityQueue();
        void heapify(int);
        void push(string,int);
        void pop();
        Node top();
        bool isEmpty();
        int size();
        void display();
        void displayBIG();
};

priorityQueue::priorityQueue(){
}

//o(1)
int priorityQueue::parent(int index){
    return (index-1) / 2;
}

//o(1)
int priorityQueue::lChild(int index){
    return 2*index + 1;
}

//o(1)
int priorityQueue::rChild(int index){
    return 2*index + 2;
}

//O(LOG N)
void priorityQueue::push(string ip,int priority){
    Node auxNode(priority,ip);
    this->heapTree.push_back(auxNode);
    int i = this->heapTree.size() - 1;

    while (i != 0 && this->heapTree[parent(i)].key < this->heapTree[i].key) {
            swap(this->heapTree[parent(i)], this->heapTree[i]);
            i = parent(i);
    }
}

//O(log n)
void priorityQueue::pop(){
    Node auxNode(INT_MIN,"INT_MIN");
    this->heapTree[0] = auxNode;
    heapify(0);
    this->heapTree.pop_back();
    return;
}

Node priorityQueue::top(){
    return this->heapTree[0];
}


void priorityQueue::display(){
    for (int i = 0; i < this->heapTree.size();i++){
        cout << "Mi ip es " << this->heapTree[i].ip <<  " y me he repetido " << this->heapTree[i].key << " veces " << endl;
    }
}

//O(log n)
void priorityQueue::heapify(int index){
    int left = lChild(index);
    int right = rChild(index);
    int largest = index;
    if (left <= this->heapTree.size() && this->heapTree[left].key > this->heapTree[largest].key) {
            largest = left;
    }
    if (right <= this->heapTree.size() && this->heapTree[right].key > this->heapTree[largest].key) {
            largest = right;
    }
    if (largest != index) {
        swap(this->heapTree[index],this->heapTree[largest]);
        heapify(largest);
        }

}

void fillPQ(priorityQueue &prioQ,unordered_map<string,int> mapa){
    for (auto x : mapa){
        prioQ.push(x.first,x.second);
    }
}

int main(){
    unordered_map <string,int> HASH = fillHash();
    priorityQueue PQ;
    
    fillPQ(PQ,HASH);

    //Add to new txt file
    fstream sortedBitacora;
	sortedBitacora.open("ips_con_mayor_acceso.txt", ios::out);

	for (int i = 0; i < 5;i++){
        sortedBitacora << "Mi ip es " << PQ.top().ip << " y me he repetido " << PQ.top().key << " veces " << endl;
        PQ.pop();
    }

    cout << "\nAll of sorted denied entries have been added to ips_con_mayor_acceso.txt" << endl;
	sortedBitacora.close();
}