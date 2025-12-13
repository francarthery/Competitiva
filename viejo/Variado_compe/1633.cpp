#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main(){

    int n, t, c, tiempo;

    while(cin >> n){
        long long rta = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq1, pq2; //pq2 contiene los que ya podemos procesar

        for(int i = 0; i < n; i++){
            cin >> t >> c;
            pq1.push({t, c});
        }

        ii aux = pq1.top();
        pq2.push({aux.second, aux.first}); //Inicialmente pq2 contiene el elemento con el t menor
        pq1.pop();
        tiempo = aux.first;

        while(!pq2.empty()){
            rta += tiempo - pq2.top().second;
            tiempo += pq2.top().first; //Sumamos el tiempo de la tarea de menor tiempo
            pq2.pop();

            while(!pq1.empty() and (pq1.top().first <= tiempo or pq2.empty())){
                if(pq2.empty() and pq1.top().first > tiempo)tiempo = pq1.top().first;
                aux = pq1.top();
                pq2.push({aux.second, aux.first});
                pq1.pop();
            }
        }

        cout << rta << endl;
    }

    return 0;
}