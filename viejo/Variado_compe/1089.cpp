#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, inicio, x;

    while(cin >> n and n != 0){
        int cont = 0;
        bool subiendo = false, bajando = false;
        vector<int> v(n);
        
        for(int i = 0; i < n; i++)
            cin >> v[i];

        for(int i = 1; i < n; i++){
            if(v[i] > v[i - 1] and !subiendo){
                subiendo = true;
                bajando = false;
                cont++;
            }
            else if(v[i] < v[i - 1] and !bajando){
                bajando = true;
                subiendo = false;
                cont++;
            }
        }
        if(v[0] > v[1] and bajando and v[0] > v[n - 1])
            cont++;
        if(v[0] < v[1] and subiendo and v[n - 1] > v[0])
            cont++;

        cout << cont << endl;
    }

    return 0;
}