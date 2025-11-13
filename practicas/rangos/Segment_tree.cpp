#include <iostream>

using namespace std;

int *T, *a;

void init(int node, int l, int r){ //Inicializacion del arbol. Cada indice es un nodo. 
    if(l == r) T[node] = a[l];
    else{
        int mi = (l + r) / 2;
        init(2 * node, l, mi);
        init(2 * node + 1, mi + 1, r);
        T[node] = T[2 * node] + T[2 * node + 1];
    }
}

void update(int x, int val, int node, int l, int r){
    if(r < x or l > x) return; //Si salimos de rango no se hace ningun cambio
    if(l == r) T[node] = val; //Solo vamos se podra cambiar el elemento en las posicion x
    else{
        int mi = (l + r) / 2;
        update(x, val, 2 * node, l, mi);
        update(x, val, 2 * node + 1, mi + 1, r);
        T[node] = (T[2 * node] + T[2 * node + 1]);
    }
}

int query(int x, int y, int node, int l, int r){ //Devuelve suma desde x hasta y
    if(r < x or l > y) return 0; //Retornamos 0 ya que algo + 0 = 0

    if(x <= l and r <= y){ //Si el rango entero forma parte de la solucion, lo tenemos en cuenta
        return T[node]; //Mientras que el rango [l, r] no este contenido o sea igual al rango [x, y] no se hara nada
    } else{
        int mi = (l + r) / 2;
        return query(x, y, 2 * node, l, mi) + query(x, y, 2 * node + 1, mi + 1, r);
    }
}

int main(){

    int n;
    cin >> n;
    
    a = new int[n]; //Array original
    T = new int[n * 4]; //Arbol

    for(int i = 0; i < n; i++) cin >> a[i];

    init(1, 0, n - 1);

    for(int i = 1; i < 16; i++) cout << T[i] << " ";

    cout << endl << query(1, 4, 1, 0, n - 1) << endl;

    return 0;
}