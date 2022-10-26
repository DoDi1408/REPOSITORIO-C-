#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data):data(data), left(NULL), right(NULL){}
};


// o log n
Node* minNode(Node* root) {
    Node* auxNode = root;
    while (auxNode->left != NULL) {
      auxNode = auxNode->left;
    }
    return auxNode;
}


// o(1)
void rightRotate(Node *&root){
    Node* Node1 = root->left;
    Node* Node2 = Node1->right;

    Node1->right = root;
    root->left = Node2;

    return;
}
// o(1)
void leftRotate(Node *&root){
    Node* Node1 = root->right;
    Node* Node2 = Node1->left;

    Node1->left = root;
    root->right = Node2;

    return;
}

// o(n)
int height(Node *&root){
    if (root == NULL){
        return -1;
    }
    else{
        int left,right;
        left = height(root->left);
        right = height(root->right);

        if (left > right){
            return(left + 1);
        }
        else{
            return(right + 1);
        }
    }
}
// O(N)
int getBalanceFactor(Node *&root){
    if(root == NULL){
        return -1;
    }
    return height(root->left) - height(root->right);
}

// O(log n)
void insert(int value,Node *&root){
    if (root == NULL){
        root = new Node (value);
    }
    else{
        if(value < root->data){
            insert(value,root->left);
        }
        else if (value > root->data){
            insert(value,root->right);
        }
        else{
            cout << "Repeated element" << endl;
            return;
        }
    }
    // rotations
    int bf = getBalanceFactor(root);

    if (bf > 1){
        int bf2 = getBalanceFactor(root->left);
        if (bf2 >= 1){
            rightRotate(root);
        }
        else if (bf2 <= -1){
            leftRotate(root->left);
            rightRotate(root);
        }
    }
    else if (bf < -1){
        int bf2 = getBalanceFactor(root->right);
        if (bf2 >= -1){
            leftRotate(root);
        }
        else if (bf2 <= 1){
            rightRotate(root->right);
            leftRotate(root);
        }
    }
}

// o(log n)
void del(int value,Node *&root){
    if (root == NULL){
      return;
    }
    else{
        if(value < root->data){
            del(value,root->left);
        }
        else if (value > root->data){
            del(value,root->right);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                root = temp;
                delete temp;
            } 
            else if (root->right == NULL) {
                Node* temp = root->left;
                root = temp;
                delete temp;
            }
            else{
            Node* temp = minNode(root->right);
            root->data = temp->data;
            del(temp->data,root->right);
            }
        }
    }
    
    // rotations
    int bf = getBalanceFactor(root);

    if (bf > 1){
        int bf2 = getBalanceFactor(root->left);
        if (bf2 >= 1){
            rightRotate(root);
        }
        else if (bf2 <= -1){
            leftRotate(root->left);
            rightRotate(root);
        }
    }
    else if (bf < -1){
        int bf2 = getBalanceFactor(root->right);
        if (bf2 >= -1){
            leftRotate(root);
        }
        else if (bf2 <= 1){
            rightRotate(root->right);
            leftRotate(root);
        }
    }
}

// o(N)
void print(Node* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
// o (N)
int size(Node* root){
    if(root == NULL){
        return 0;
    }
    else {
        return (size(root->left) + 1  + size(root->right));
    }
}
// O (LOG N)
bool find(Node* root, int toFind){
    Node* auxNode;
    auxNode = root;
    while (auxNode){
        if (auxNode->data == toFind){
            return true;
        }
        else if (auxNode->data < toFind){
            auxNode = auxNode->right;
        }
        else{
            auxNode = auxNode->left;
        }
    }
    return false;
}
