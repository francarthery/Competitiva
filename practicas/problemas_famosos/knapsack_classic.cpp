#include <bits/stdc++.h>

using namespace std;

//Complejidad 2^n
//El algoritmo consiste en analizar todas las posibilidades de objetos que meter y sacar el max

int n, cap;
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
    
    cin >> n >> cap;

    peso.resize(n + 1);
    valor.resize(n + 1);
    dp.assign(n + 1, vector<int>(cap + 1, -1));

    for(int i = 1; i <= n; i++){
        cin >> peso[i] >> valor[i];
    }

    cout << mochila(n, cap) << '\n';


    return 0;
}