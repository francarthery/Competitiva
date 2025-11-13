#include <bits/stdc++.h>

using namespace std;

int n, *padre;

int Find(int node){
    if(padre[node] == node) return node;
    return padre[node] = Find(padre[node]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    padre[b] = a;
}


int main(){

    int m, a, b, rta = 0;
    cin >> n >> m;
    padre = new int[n];
    
    for(int i = 0; i < n; i++) padre[i] = i;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Union(a, b);
    }

    for(int i = 0; i < n; i++){
        if(padre[i] == i)
            rta++;
    }

    cout << rta << endl;

    return 0;
}