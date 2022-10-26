#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};
void displayList(Node* head){
    cout << "NULL<=";
    while (head != NULL) {
      cout<<head->data<<"<=>";
      head = head->next;
   }
   if(head == NULL){
        cout<<"NULL";
   }
   cout << endl;
}
//O(N)
void insertElement(int value, Node* head){
    Node* newNode = new Node; // creo un nuevo nodo de manera dinamica
    Node* last = head; // creo un nodo auxiliar para encontrar la cola, lo inico en head
    newNode->data = value; // la data de mi nuevo nodo es mi parametro value
    newNode->next = NULL; // quiero que sea el final asi que su apuntandor de next deberia de ser null
    while (last->next != NULL){
        last = last->next; 
    }
    last->next = newNode;
    newNode->prev = last;
    displayList(head);
    return;
}
//O(N)
Node* searchElement(int idx, Node* head){ // by number of element starts in 0
    Node* aux = head;
    for (int i=0;i<idx;i++){
        if(aux==NULL){
            cout << "Index out of range " << endl;
            return NULL;
        }
        aux = aux->next;
    }
    return aux;
}
//o(n)
void updateElement(int value,int idx, Node* head){
    Node* updateNode = searchElement(idx, head);
    updateNode->data = value;
    displayList(head);
    return;
}
// O(N)
void deleteElement(int idx, Node** head){
    Node* deleteNode = searchElement(idx, *head);
    if (*head == deleteNode){
        deleteNode = *head;
        Node *auxNode = deleteNode->next;
        auxNode->prev = NULL;
        *head = auxNode;
        delete deleteNode;
        displayList(*head);
        return;
    }
    if (deleteNode->next == NULL){
        deleteNode->prev->next = NULL;
        delete deleteNode;
        displayList(*head);
        return;
    }
    if (deleteNode->next != NULL){
        deleteNode->next->prev = deleteNode->prev;
        deleteNode->prev->next = deleteNode->next;
        delete deleteNode;
        displayList(*head);
        return;
    }
}
int main() {
    cout << endl;
    Node* head = new Node;
    head->prev = NULL;
    head->next = NULL;
    head->data =  1;
    insertElement(3,head);
    insertElement(5,head);
    insertElement(11,head);
    insertElement(4,head);
    insertElement(7,head);
    updateElement(99,3,head);
    updateElement(-99,0,head);
    updateElement(54,5,head);
    deleteElement(0,&head);
    deleteElement(1,&head);
    deleteElement(3,&head);
    return 0;
}