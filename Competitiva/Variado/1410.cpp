#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, d, x, min_a;
    
    while(cin >> a >> d and (a != 0 or d != 0)){
        vector<int> def(d);
        min_a = 10000;

        for(int i = 0; i < a; i++){
            cin >> x;
            min_a = min(min_a, x); //Atacante mas adelantado
        }

        for(int i = 0; i < d; i++){
            cin >> def[i];
        }

        sort(def.begin(), def.end()); //Ordenamos defensores de forma ascendente

        cout << (def[1] > min_a ? "Y" : "N") << endl;
    }

    return 0;
}