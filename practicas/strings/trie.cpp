#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
    TrieNode* childNode[26]; //Arreglo de punteros para los hijos de cada nodo
    bool wordEnd;

    TrieNode(){ //Constructor
        wordEnd = false;
        for(int i = 0; i < 26; i++) childNode[i] = NULL;
    }
};

void insert_key(TrieNode* root, string &key){ //O(numero_palabras * largo_pal_mas_larga)
    TrieNode* currentNode = root;

    for(char c : key){ //Recorro el arbol con la palabra que busco
        if(currentNode -> childNode[c - 'a'] == NULL){ //Verifico si existe un nodo para ese caracter
            TrieNode* newNode = new TrieNode(); //Si no existe lo creo
            currentNode -> childNode[c - 'a'] = newNode;
        }
        currentNode = currentNode -> childNode[c - 'a']; //Avanzo de nodo
    }
    currentNode -> wordEnd = 1;
}

bool search_key(TrieNode* root, string &key){ //Similar a insert pero si no encuentro termina
    TrieNode* currentNode = root;

    for(char c : key){
        if(currentNode -> childNode[c - 'a'] == NULL) return false;
        currentNode = currentNode -> childNode[c - 'a'];
    }
    return (currentNode -> wordEnd);
}

int main(){

    TrieNode* root = new TrieNode();

    vector<string> inputStrings = { "and", "ant", "do", "geek", "dad", "ball"};
    for(int i = 0; i < inputStrings.size(); i++) insert_key(root, inputStrings[i]);

    vector<string> searchstr = { "do", "geek", "bat"};
    for(int i = 0; i < searchstr.size(); i++){
        cout << "El string \"" << searchstr[i] << "\" " << (search_key(root, searchstr[i]) ? "" : "no") << " esta presente en el arbol\n"; 
    }
}