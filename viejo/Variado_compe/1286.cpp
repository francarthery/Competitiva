#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<int> peso, valor;
vector<vector<int>> dp;

int mochila(int i, int libre){
    if(libre < 0) return -1000000000; //Nos pasamos de peso
    if(i == 0) return 0; //Ya no quedan objetos
    if(dp[i][libre] != -1) return dp[i][libre]; 

    int op1 = mochila(i - 1, libre); //No elijo ese objeto
    int op2 = valor[i] + mochila(i - 1, libre - peso[i]); //Elijo ese objeto

    return dp[i][libre] = max(op1, op2); //Por cada cantidad de objetos restantes y espacio libre, guardo la maxima ganancia.
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> n and n != 0){
        cin >> p;
        peso.resize(n + 1);
        valor.resize(n + 1);
        dp.assign(n + 1, vector<int>(p + 1, -1));

        for(int i = 1; i <= n; i++){
            cin >> valor[i] >> peso[i];
        }

        cout << mochila(n, p) << " min.\n";
    }

    return 0;
}