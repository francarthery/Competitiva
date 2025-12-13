#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Problema 1764 beecrowd

int N, lider[200000];

vector< pair< int, pair<int, int> > > v;

void init(){
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++)
        lider[i] = i;
}

void Union(int a, int b){
    lider[b] = a;
}

int Find(int n){
    if(n == lider[n]) return n;
    return(lider[n] = Find(lider[n]));
}

long long unsigned Kruskal(){
    int a, b;
    long long unsigned sum = 0;
    init();

    for(unsigned i = 0; i < v.size(); i++){
        a = Find(v[i].second.first);
        b = Find(v[i].second.second);
        if(a != b){ //Si los elementos de la arista no tienen el mismo padre
            sum += (v[i].first); //Sumamos el peso de esta arista al arbol total
            Union(a, b); //Use a los padres de los conjuntos
        }
    }
    return sum;
}

int main(){

    int m, a, b, p;
    long long unsigned sum;

    while(cin >> N >> m and N != 0 and m != 0){

        sum = 0;

        for(int i = 0; i < m; i++){
            cin >> a >> b >> p;
            v.push_back(make_pair(p, make_pair(a, b)));
            sum += p;
        }

        cout << sum - Kruskal() << endl; //Luces totales - luces optimizadas

        v.clear(); //Liberamos grafo
    }

    return 0;
}