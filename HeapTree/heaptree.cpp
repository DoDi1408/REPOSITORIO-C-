#include <iostream>
#include <vector>
#include <limits.h>

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

// PRIVATE FUNCITONS

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


// PUBLIC FUNCTIONS

//o(1)
int priorityQueue::size(){
    return this->heapTree.size();
}

//o(1)
bool priorityQueue::isEmpty(){
    if (this->heapTree.empty()){
        return true;
    }
    return false;
}


//o(1)
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

//O(LOG N)
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
void priorityQueue::display(){
    for (int i = 0; i < this->heapTree.size();i++){
        cout << this->heapTree[i].value << endl;
    }
}
int main(){
    priorityQueue PQ;
    if (PQ.isEmpty()){
        cout << "Estoy vacio" << endl;
        cout << endl;
    }
    
    PQ.push(5,1);
    PQ.push(6,5);
    PQ.push(1,10);
    PQ.push(3,7);
    PQ.display();
    if (PQ.isEmpty()){
        cout << "Estoy vacio" << endl;
    }
    cout << endl;
    cout << PQ.top() << endl;

    PQ.pop();

    PQ.push(10,3);
    PQ.push(11,4);
    PQ.push(12,2);
    PQ.push(13,6);

    cout << endl;
    PQ.display();
}