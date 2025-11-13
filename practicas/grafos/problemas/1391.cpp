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
vvii previous(MAX); //Almacena vectores de par(nodo del que llego, arco con el que llego)

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
            
            if(cost != -1 and D[v2] > D[v] + cost){ //Si el arco se uso antes el coste va a ser -1 para no usarlo
                if(D[v2] != 1000000000){ //Si la distancia a v2 ya se calculo y era mayor la borramos
                    Q.erase(Q.find(ii(D[v2], v2))); 
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2)); //Se insera en el conjunto un nuevo nodo a visitar y la distancia a este.
                previous[v2].clear(); //Si hay una ruta mas corta se eliminan las rutas anteriores guardadas.
                previous[v2].push_back(make_pair(v, it - G[v].begin())); //Almaceno nodo y arco con el que llego de la forma mas corta
            }
            else if(cost != -1 and D[v2] == D[v] + cost){ // Si hay otra ruta de igual largo tambien se registra
                previous[v2].push_back(make_pair(v, it - G[v].begin())); 
            }
        }
    }
}

void delete_path(int fin, int inicio){
    if(fin == inicio) return;
    else{
        for(auto i : previous[fin]){ //Borramos el arco con el que llegamos a fin y repetimos el proceso con el nodo origen
            delete_path(i.first, inicio);
            G[i.first][i.second].second = -1;
        }
    }
}

int main(){

    int m, ini, fin, a, b, p;
    while(cin >> n >> m and (n != 0 or m != 0)){
        cin >> ini >> fin;

        for(int i = 0; i < m; i++){
            cin >> a >> b >> p;
            G[a].push_back(ii(b, p));
        }

        Dijkstra(ini); // Calculamos ruta mas corta
        delete_path(fin, ini); //Borramos los arcos ya usados

        D.assign(MAX, MAXINT); //Reiniciamos los vectores
        previous.assign(MAX, vector<pair<int, int>>());
        
        Dijkstra(ini); // Calculamos ruta ignorando arcos de la ruta mas corta
        
        
        if(D[fin] == MAXINT)
            cout << -1 << endl; //No hay un camino posible a fin
        else
            cout << D[fin] << endl; //Distancia a fin
        
        
        D.assign(MAX, MAXINT); //Reiniciamos los vectores
        previous.assign(MAX, vector<pair<int, int>>());
        G.assign(MAX, vector<pair<int, int>>());
        
    }

    return 0;
}
