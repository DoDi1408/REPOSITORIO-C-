#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
    int value;
    int priority;
};
class priorQueue{
    private:
        int N, numNodes;
        Node *PQ;;
    public:
        priorQueue(int size)
        {
        N = size;
        PQ = new Node[size];
        numNodes = -1;
        }
        ~priorQueue(){
        cout << "Destructor: Erase Queue" << endl;
        delete[] PQ;
        }
        void enqueue(int,int);
        Node *dequeue();
        void display();
        int peek();
        void display(int);
        bool isEmpty();
        bool isFull();
};
void priorQueue::enqueue(int value, int priority){
    if (isFull){
        return;
    }
    // increase current size
    numNodes++;
    // insert the element
    PQ[numNodes].value = value;
    PQ[numNodes].priority = priority;
}
Node *priorQueue::dequeue(){
    if(isEmpty){
        return NULL;
    }
    int ind = peek();
    Node *Aux = &PQ[ind];

    for (int i = ind; i < numNodes; i++){
        PQ[i] = PQ[i + 1];
    }
    return Aux;
}
int priorQueue::peek(){
    int highestPriority = INT_MIN;
    int ind = -1;
    for (int i = 0; i <= numNodes; i++){
        if (highestPriority < PQ[i].priority){
            highestPriority = PQ[i].priority;
            ind = i;
        }
        else if(highestPriority == PQ[i].priority && PQ[i].value > PQ[ind].value){
            highestPriority = PQ[i].priority;
            ind = i;
        }
    }
    return ind;
}
bool priorQueue::isFull(){
    if (numNodes == N-1){
        return true;
    }
    return false;
}
bool priorQueue::isEmpty(){
    if (numNodes == -1){
        return true;
    }
    return false;
}
void priorQueue::display(int inx){
    cout << PQ[inx].value << endl << endl;
}
void priorQueue::display(int){
    cout << "Elements: ";
    for (int i=0; i <= numNodes; i++){
        cout << PQ[i].value << " ";
    }
    cout << endl << endl;
}