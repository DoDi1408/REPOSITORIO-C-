//RODRIGO ALEJANDRO CHAVEZ AVALOS A01635547
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

//o(n)

int height(Node *&root){
    if (root == NULL){
        return 0;
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
//O(n) 
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//O(n) 
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//O(n) 
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
//o(n)
void CurrentLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
       CurrentLevel(root->left, level-1);
       CurrentLevel(root->right, level-1);
    }
}
//o n
void LevelOrder(Node* root){
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        CurrentLevel(root, i);
}

//O(log n)
void insert(int value, Node *&root){
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
}
//o (N)
void visit(Node* root, int type){
    if(type == 1){
        preOrder(root);
    }
    else if (type == 2){
        inOrder(root);
    }
    else if (type == 3){
        postOrder(root);
    }
    else if(type == 4){
        LevelOrder(root);
    }
    else{
        cout << "You have entered an invalid number" << endl;
    }
}
// voy a considerar que un nodo root tiene una altura de 1     

// O (N)
int ancestors(Node* root, int value){
    if (root == NULL){
        return 0;
    }
    else if (root->data == value){
        return 1;
    }  
    else{
        int left,right;
        left = ancestors(root->left,value);
        right = ancestors(root->right,value);

        if (left == 1){
            cout << root->data << endl;
            return 1;
        }
        else if (right == 1){
            cout << root->data << endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    return -1;
}

// o log n
int getLevel(Node* root, int toFind){
    Node* auxNode;
    auxNode = root;
    int level = 0;
    while (auxNode){
        if (auxNode->data == toFind){
            return level;
        }
        else if (auxNode->data < toFind){
            auxNode = auxNode->right;
        }
        else{
            auxNode = auxNode->left;
        }
        level+=1;
    }
    return -1;
}

int size(Node* root){
    if(root == NULL){
        return 0;
    }
    else {
        return (size(root->left) + 1  + size(root->right));
    }
}
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

int main(){
    Node *root(NULL);
    insert(18,root);
    insert(22,root);
    insert(24,root);
    insert(20,root);
    insert(10,root);
    insert(15,root);
    insert(7,root);
    cout << "Ancestors of node with data 15" << endl;
    ancestors(root,15);
    cout << endl;
    cout << "Ancestors of node with data 24" << endl;
    ancestors(root,24);
    cout << "My height is "<< height(root) << endl;
    cout << "Node with data 15 is on level " << getLevel(root, 15) << endl;
    cout << "Node with data 10 is on level " << getLevel(root, 10) << endl;
    cout << "my size is " << size(root) << endl;
    cout << "is 7 on this tree " << find(root, 18) << endl;
}

