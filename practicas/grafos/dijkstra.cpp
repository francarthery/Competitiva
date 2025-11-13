#include <bits/stdc++.h>

using namespace std;

//Este algoritmo calcula la distancia de un nodo a todos los otros nodos del grafo.

typedef vector<int> vi; //'v' equivale a vector e 'i' a entero. vi es vector de enteros.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii>vvii;

const int MAX = 1001;
const int MAXINT = 1000000000; //Peso que nunca va a alcanzar un nodo

int n;

vvii G(MAX); //Almacena el grafo como una lista de adyacencia dinamica.
vi D(MAX, MAXINT); //Almacena distancia desde nodo 's' a todos los demas

void Dijkstra(int s){
    set<ii> Q; //Conjunto de pares (distancia, nodo) ordenados por distancia
    D[s] = 0; //La distancia a si mismo es 0
    Q.insert(ii(0, s));

    while(!Q.empty()){
        ii top = *Q.begin(); //Extraemos el nodo con distancia mas corta del conjunto
        Q.erase(Q.begin());

        int v = top.second; //Nodo
        int d = top.first;  //Distancia desde 's' a ese nodo

        vii::const_iterator it;

        for(it = G[v].begin(); it != G[v].end(); it++){ //Iteramos en los nodos adyacentes a 'v'
            int v2 = it -> first;
            int cost = it -> second;
            
            if(D[v2] > D[v] + cost){ //Nos fijamos si la ruta actual es mas corta que la ya calculada
                if(D[v2] != 1000000000){ //Si la distancia a v2 ya se calculo y era mayor la borramos
                    Q.erase(Q.find(ii(D[v2], v2))); 
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2)); //Se insera en el conjunto un nuevo nodo a visitar y la distancia a este.
            }
        }
    }
}

int main(){

    int m, ini, fin, a, b, p;
    cin >> n, m, ini, fin;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> p;
        G[a].push_back(ii(b, p));
        G[b].push_back(ii(a, p));
    }

    Dijkstra(ini);
    cout << D[fin] << endl;

    return 0;
}