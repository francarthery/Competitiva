#include <iostream>

using namespace std;

/*
En los arboles las hojas a la vez son padres de dos nodos NULL.

*/

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr;
    return newNode;
}

int main(){

    //Inicio arbol
    Node* root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);

    return 0;
}

/*
Arbol:

    1
   / \
  2   3
 /
4

*/