#include <iostream>

using namespace std;

struct Node{
    char info;
    Node *left;
    Node *right;
};

Node *new_node(char data){ //Devuelve nuevo nodo con la info
    Node* nuevo_nodo = new Node;
    nuevo_nodo -> info = data;
    nuevo_nodo -> right = nuevo_nodo -> left = nullptr;
    return nuevo_nodo;
}

void print_tree(Node *raiz){
    if(raiz == nullptr) return;

    print_tree(raiz -> left);
    print_tree(raiz -> right);
    cout << raiz -> info;

}

void create_tree(Node *&node, string pre, string in){
    if(pre.size() == 0) return;
    else{
        node = new_node(pre[0]);
        int pos_raiz = in.find(pre[0]); //Localizamos raiz. Elementos a su derecha e izquierda representan elementos de esas ramas
        //largo_izq = pos_raiz
        //largo_der = in.size() - pos_raiz
        
        create_tree(node -> left, pre.substr(1, pos_raiz), in.substr(0, pos_raiz)); //Rama izquierda
        create_tree(node -> right, pre.substr(pos_raiz + 1, in.size() - pos_raiz), in.substr(pos_raiz + 1, in.size() - pos_raiz)); //Rama derecha
    }
}

int main(){

    string s1, s2;

    while(cin >> s1 >> s2){
        Node* arbol = nullptr;
        create_tree(arbol, s1, s2);
        print_tree(arbol);
        cout << endl;
    }

    return 0;
}