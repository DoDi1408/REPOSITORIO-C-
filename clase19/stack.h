#include <iostream>
using namespace std;

struct Node{
    int num;
};
class Stack{
    private:
        int N, Top;
        Node *st;
    public:
    Stack(int size)
    {
        Top = -1;
        N = size;

        st = new Node[N];
    }
    ~Stack()
    {
        cout << "Destructor: Erase Stack" << endl;
        delete [] st;
    }
    void Push(int);
    Node *Pop();
    int *Peek();
    bool isEmpty();
};

void Stack::Push(int NUM){
    if(Top == N-1){
        cout << "The stack is full (Overflow)." << endl;
        return;
    }
    Top++;
    st[Top].num = NUM;
}

struct Node *Stack::Pop(){
    if(Top < 0){
        cout << "The stack is empty (Underflow)." << endl;
        return;
    }
    Top--;
    return &st[Top + 1];
}

int *Stack::Peek(){
    if(Top < 0){
        return NULL;
    }
    return &(st[Top].num);
}

bool Stack::isEmpty(){
    if(Top < 0){
        return true;
    }
    return false;
}