#include <bits/stdc++.h>

using namespace std;

#define sc second
#define fr first

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x, m, min_d, dif;

    while(cin >> n and n != 0){
        vector<pair<priority_queue<int>, pair<int, int>>> v(n); // (notas curso, (total, cant a la derecha de T))
        vector<bool> notas(1001); //notas que al menos uno saco
        min_d = 1000000;

        for(int i = 0; i < n; i++){ //Pido todos los datos
            cin >> m;
            v[i].sc.fr = m; //Almaceno la cantidad de elementos que hay en esa division
            for(int j = 0; j < m; j++){
                cin >> x;
                notas[x] = true; //Guardo que alguien saco esa nota
                v[i].fr.push(x);
            }
        }

        for(int i = 1000; i >= 0; i--){
            dif = 0;
            if(notas[i]){
                for(int j = 0; j < n; j++){
                    while(!v[j].fr.empty() and v[j].fr.top() == i){
                        v[j].sc.sc++; //Pasa a la derecha
                        v[j].fr.pop(); //Ya no se usa ese elemento
                    }
                    dif += abs((v[j].sc.sc << 1) - v[j].sc.fr); //Dif = abs(2 * der - total)
                }
                min_d = min(min_d, dif);
            }
        }

        cout << min_d << '\n';
    }
    
    return 0;
}