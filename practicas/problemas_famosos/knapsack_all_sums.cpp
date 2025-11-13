#include <bits/stdc++.h>

using namespace std;

//Calculo que sumas se pueden hacer con un conjunto de numeros

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, m = 0;
    cin >> n;
    vector<int> w(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> x;
        w[i] = x;
        m += x;
    }

    vector<int> possible(m + 1); //El max al que puedo llegar es la suma de todos los pesos
    possible[0] = 1;

    for(int k = 1; k <= n; k++){
        for(int x = m - w[k]; x >= 0; x--){
            possible[x + w[k]] |= possible[x];
        }
    }

    for(int i = 0; i <= m; i++) {
        cout << (possible[i] == 0 ? "no" : "si") << " ";
    }

    return 0;
}