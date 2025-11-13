/*
Arbol: "D:\c++\arbol_ejemplo.png"
Algoritmos DFS (Depth First Search)
preorden(data, left, right)  1 2 4 5 9 3 6 7 15 primera vez que paso
inorder(left, data, right) 4 2 9 5 1 6 3 15 7
postorder(left, right, data) 4 9 5 2 6 15 7 3 1 ultima vez que paso

)
*/
#include <iostream>

using namespace std;

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

void printTree(Node* root){
    
    if(root == nullptr) return;
    
    //Recorremos en preorden. Cambiando el orden de las sentencias elejimos la forma de hacerlo
    cout << root -> data << " ";
    printTree(root -> left);
    printTree(root -> right);
}

int main(){

    //Nivel 1
    Node* root = createNode(1);
    //Nivel 2
    root -> left = createNode(2);
    root -> right = createNode(3);
    //Nivel 3
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root -> right -> left = createNode(6);
    root -> right -> right = createNode(7);
    //Nivel 4
    root -> left -> right -> left = createNode(9);
    root -> right -> right -> left = createNode(15);

    printTree(root);

    return 0;
}