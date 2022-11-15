
// RODRIGO ALEJANDRO CHAVEZ AVALOS
// A01635547
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    int priority;
};

class priorityQueue{
    private:
        vector<Node> heapTree;
        void heapify(int);
        int parent(int);
        int lChild(int);
        int rChild(int);
    public:
        priorityQueue();
        void push(int,int);
        void pop();
        int top();
        bool isEmpty();
        int size();
        void display();
};

priorityQueue::priorityQueue(){
}

//O(log n)
void priorityQueue::heapify(int index){
    int left = lChild(index);
    int right = rChild(index);
    int largest = index;
    if (left <= this->heapTree.size() && this->heapTree[left].priority > this->heapTree[largest].priority) {
            largest = left;
    }
    if (right <= this->heapTree.size() && this->heapTree[right].priority > this->heapTree[largest].priority) {
            largest = right;
    }
    if (largest != index) {
        swap(this->heapTree[index],this->heapTree[largest]);
        heapify(largest);
        }

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

int priorityQueue::top(){
    if (this->heapTree.empty()){
        return -1;
    }
    return this->heapTree[0].value;
}

//O(log n)
void priorityQueue::pop(){
    if (this->heapTree.empty()){
        return;
    }
    Node auxNode;
    auxNode.priority = INT_MIN;
    auxNode.value = INT_MIN;
    this->heapTree[0] = auxNode;
    heapify(0);
    this->heapTree.pop_back();
    return;
}

void priorityQueue::push(int newNum,int priority){
    Node auxNode;
    auxNode.priority = priority;
    auxNode.value = newNum;
    this->heapTree.push_back(auxNode);
    int i = this->heapTree.size() - 1;

    while (i != 0 && this->heapTree[parent(i)].priority < this->heapTree[i].priority) {
            swap(this->heapTree[parent(i)], this->heapTree[i]);
            i = parent(i);
    }
}

class Graph{
    private:
        vector < vector<int> > adjacencyMatrix;
        list<int> *adjList;
        int numVertices;
        bool *visited;
    public:
        // n^2 time complexity
        Graph(int V){
            numVertices = V;
            adjList = new list<int> [V];
            visited = new bool[V];
            for (int i=0;i<V;i++){
                vector<int> vec;
               for (int j=0;j<V;j++){
                    vec.push_back(0);
                }
                adjacencyMatrix.push_back(vec);
            }
        }
        //O (1)
        ~Graph(){
            delete [] adjList;
            delete [] visited;
        }
        void addEdge(int,int);
        void ResetVisited();
        void printGraph();
};

void Graph::addEdge(int s, int d){
    if (s >= numVertices || s < 0){
        return;
    }
    if (d >= numVertices || d < 0){
        return;
    }
    this->adjList[s].push_back(d);
    this->adjacencyMatrix[s][d] = 1;
}


void fillGraph(Graph& grafo,unordered_map<int,int>& inDegree, unordered_map<int,int>& outDegree){
    istringstream iss;
    ifstream file;
    string line, month, day, hour, ip, num_str;
    file.open("bitacora.txt");

    while (getline(file, line)){
        int cont = 0, start = 0;
        iss.str(line);
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

        for(int i=0; i<vec.size()-1;i++){
            grafo.addEdge(vec[i],vec[i+1]);
            inDegree[vec[i+1]] += 1;
            outDegree[vec[i]] += 1;
        }
    }
    return;
}
int main(){

    priorityQueue inDegreePQ;
    priorityQueue outDegreePQ;

    unordered_map<int,int> inDegree;
    unordered_map<int,int> outDegree;
    Graph grafo(999);
    fillGraph(grafo,inDegree,outDegree);
    
    for (auto x : inDegree){
        inDegreePQ.push(x.first,x.second);
    }
    
    for (auto x : outDegree){
        outDegreePQ.push(x.first,x.second);
    }

    cout << "TOP 5 DE INDEGREE" << endl << endl;
    for(int i=1;i<=5;i++){
        cout << "El valor numero " << i << " del inDegree es " << inDegreePQ.top() << endl;
        cout << "Tiene un total de: " << inDegree[inDegreePQ.top()] << " conexiones entrantes (indegree)" << endl;
        inDegreePQ.pop();
        cout << endl;
    }

    cout << "TOP 5 DE OUTDEGREE" << endl << endl;
    for(int i=1;i<=5;i++){
        cout << "El valor numero " << i << " del outDegree es " << outDegreePQ.top() << endl;
        cout << "Tiene un total de: " << outDegree[outDegreePQ.top()] << " conexiones salientes (outdegree)" << endl;
        outDegreePQ.pop();
        cout << endl;
    }

    return 0;
}
