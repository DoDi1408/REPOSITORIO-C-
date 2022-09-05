#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <class T> class CustomLinkedList{
        Node<T> *head;
        public:
            CustomLinkedList(){
                head = NULL;
            }
            ~CustomLinkedList(){
            }
            
};

#endif // LIST_H