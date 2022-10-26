#include <iostream>
using namespace std;

struct Node{
    int value;
};
class Queue{
    private:
        int front, rear, N;
        Node *Q;
    public:
    Queue(int size)
    {
        N = size;
        Q = new Node[size];
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        cout << "Destructor: Erase Queue" << endl;
        delete[] Q;
    }
    void enqueue(int);
    Node *dequeue();
    void display();
    bool isEmpty();
};

void Queue::enqueue(int NUM){
    if(front == 0 && rear == N-1){
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    Q[rear].value = NUM;
}

Node *Queue::dequeue(){
    if(front == -1){
        cout << "Queue is empty." << endl;
        return NULL;
    }
    Node *Aux = &Q[front];
    if (front >= rear){
        front = -1;
        rear = -1;
    } else{
        front++;
    }
    return Aux;
}

bool Queue::isEmpty(){
    if(front == -1){
        return true;
    }
    return false;
}

void Queue::display(){
    if(isEmpty()){
        cout << "Empty Queue" << endl;
    }
    else{
        cout << endl << "Front -> ";
        for (int i = front; i <= rear; i++){
            cout << Q[i].value << " ";
        }
        cout << "<- Rear " << endl << endl;
    }

}