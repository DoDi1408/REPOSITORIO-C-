#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <limits.h>

// RODRIGO ALEJANDRO CHAVEZ AVALOS
// A01635547
// ENTREGANDO A LAS 8 DE LA NOCHE EL 9 DE NOVIEMBRE OOOOO



using namespace std;

class Graph{
    private:
        vector < vector<int> > adjacencyMatrix;
        list<int> *adjList;
        int numVertices;
        bool *visited;
        stack<int> Stack;
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
        void DFS(int);
        void DFS2(int);
        void BFS(int);
        void printGraph();
        void topologicalSort(int);
        bool isTree();
        bool bipartiteGraph();
};

//O(1)
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
//O (V)
void Graph::ResetVisited(){
    for (int i = 0; i < this->numVertices; i++)
        this->visited[i] = false;
}

//O (V + E)
void Graph::BFS(int vertex){
    this->visited[vertex] = true;

    list<int> queue;
    queue.push_back(vertex);

    while (!queue.empty()){
        int ver = queue.front();
        cout << ver << " ";
        queue.pop_front();

        for (int i=0;i<numVertices;i++){
            if (this->adjacencyMatrix[ver][i] == 1){
                if (!visited[i]){
                visited[i] = true;
                queue.push_back(i);
            }
            }
        }
    }
}

// O(V + E) 
void Graph::DFS(int vertex){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS(i);
}
//O (V + E)
void Graph::DFS2(int vertex){
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjList[vertex];

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS2(i);
    
    this->Stack.push(vertex);
}

// O(V)
void Graph::printGraph(){
    cout << "Printing  the adjecencyMatrix " << endl << endl;;
    for (int i=0;i<numVertices;i++){
        cout << " level " << i << " :";
        for (int j=0;j<numVertices;j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// O (V)
bool Graph::isTree(){
    ResetVisited();
    DFS(0);
    for (int i = 0; i < this->numVertices; i++){
        if (!this->visited[i]){
            return false;
        }
    }
    for (int i=0;i<numVertices;i++){
        int count=0;
        for (int j=0;j<numVertices;j++){
            if(this->adjacencyMatrix[j][i] == 0){
                count+=1;
            }
        }
        if(count == numVertices){
            break;
        }
        if(i == numVertices){
            return false;
        }
    }
    ResetVisited();
    for (int i=0;i<numVertices;i++){
        for (int j=0;j<numVertices;j++){
            if(this->adjacencyMatrix[j][i] == 1){
                if(!this->visited[i]){
                    this->visited[i] = true;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}
//O (V + E)
void Graph::topologicalSort(int vertex){
    ResetVisited();
    for (int i = 0; i < numVertices; i++)
        if (!this->visited[i])
            DFS2(i);

    while (this->Stack.empty() == false) {
        cout << this->Stack.top() << " ";
        this->Stack.pop();
    }
}

// O(V+E)
bool Graph::bipartiteGraph(){

    vector<bool> color(numVertices);

    visited[0] = true;
    color[0] = true;

    list<int> queue;
    queue.push_back(0);

    while (!queue.empty()){
        int v = queue.front();
        queue.pop_front();

        for (auto u : adjList[v]){
            if (!visited[u]){
                visited[u] = true;
                color[u] = !color[v];

                queue.push_back(u);
            }
            else if (color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    
    Graph grafo(10);
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 4);
    grafo.addEdge(1, 0);
    grafo.addEdge(1, 2);
    grafo.addEdge(1, 6);
    grafo.addEdge(1, 4);
    grafo.addEdge(2, 3);
    grafo.addEdge(3, 4);
    grafo.addEdge(4, 5);
    grafo.addEdge(5, 7);
    grafo.addEdge(5, 4);
    grafo.addEdge(6, 7);
    grafo.addEdge(6, 9);
    grafo.addEdge(7, 8);
    grafo.addEdge(7, 1);
    grafo.addEdge(8, 5);
    grafo.addEdge(8, 3);
    grafo.addEdge(9, 1);
    grafo.addEdge(9, 4);

    Graph grafo2(7);
    grafo2.addEdge(0,1);
    grafo2.addEdge(0,2);
    grafo2.addEdge(1,3);
    grafo2.addEdge(1,5);
    grafo2.addEdge(2,4);
    grafo2.addEdge(2,6);
    
    Graph grafo3(6);
    grafo3.addEdge(0,1);
    grafo3.addEdge(1,2);
    grafo3.addEdge(2,3);
    grafo3.addEdge(3,0);
    grafo3.addEdge(3,4);
    grafo3.addEdge(4,3);
    grafo3.addEdge(5,0);

    if (grafo2.isTree()){
        cout << "grafo2 es el unico arbol" << endl;
    }
    if (grafo.isTree()){
        cout << "grafo no es un arbol" << endl;
    }
    if (grafo3.isTree()){
        cout << "grafo3 no es un arbol" << endl;
    }
    
    if (grafo2.bipartiteGraph()){
        cout << "grafo2 es bipartita porque todos los arboles son bipartitas " << endl;
    }
    if (grafo.bipartiteGraph()){
        cout << "grafo no es bipartita" << endl;
    }

    if (grafo3.bipartiteGraph()){
        cout << "grafo3 si es bipartita" << endl;
    }
    grafo2.topologicalSort(0);
    cout << endl;
    grafo3.topologicalSort(5);
    cout << endl;
}
