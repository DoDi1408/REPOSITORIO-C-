#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string> 
#include <sstream>


using namespace std;

struct Node {
    int key;
    string ip;
    Node *left;
    Node *right;
    Node(int key, string ip):key(key), ip(ip), left(NULL), right(NULL){}
};


unordered_map<string,int> fillHash(){

    istringstream iss;
    ifstream file;
    string line, month, day, hour, ip, num_str;
    unordered_map<string,int> output;
    file.open("bitacora.txt");
    while (getline(file, line)){
            iss.str(line);
            iss >> month >> day >> hour >> ip;
            num_str = ip.substr(0,13);
            if (output[num_str] == 0){
                output[num_str] = 1;
            }
            else{
                output[num_str] += 1;
            }
    }
    return output;
}

void insert(string value, Node *&root, int key){
    if (root == NULL){
        root = new Node (key,value);
    }
    else{
        if(key < root->key){
            insert(value,root->left,key);
        }
        else if (key > root->key){
            insert(value,root->right,key);
        }
        else{
            insert(value,root->right,key);
            return;
        }
    }
}

void fillBST(Node *&root,unordered_map<string,int> mapa){
    for (auto x : mapa){
        insert(x.first,root,x.second);
    }
}

void print(Node* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}
void printBIG(Node* root){
    if(root == NULL){
        return;
    }
    cout << "The IP " << root->ip  << " has repeated " << root->key <<  " times " << " " << endl;
    printBIG(root->right);
}

int main(){
    unordered_map <string,int> HASH = fillHash();
    Node *root(NULL);
    //for (auto x : HASH)
    //cout << x.first << " " <<
    //        x.second << endl;

    fillBST(root,HASH);
    printBIG(root);
}
