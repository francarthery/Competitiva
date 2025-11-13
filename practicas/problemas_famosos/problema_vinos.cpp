#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;
vector<vector<int>> cache;

int ganancia(int izq, int der){
    if(izq > der) return 0;
    if(cache[izq][der] != -1) return cache[izq][der];

    int a = n - der + izq;
    int op1 = p[izq] * a + ganancia(izq + 1, der);
    int op2 = p[der] * a + ganancia(izq, der - 1);
    return cache[izq][der] = max(op1, op2);
}

int main(){
    
    cin >> n;
    p.assign(n, 0);
    cache.assign(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) cin >> p[i];

    cout << ganancia(0, n - 1) << '\n';

    return 0;
}