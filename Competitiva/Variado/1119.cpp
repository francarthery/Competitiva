#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k, m, timer, cont, cont2, pos1, pos2;

    while(cin >> n >> k >> m and (n != 0 or k != 0 or m != 0)){
        vector<pair<int, int>> v(n, pair<int, int>(-1, -1)); //Vector que almacena tiempo de extraccion de elemento y que poli fue
        map<int, pair<int, int>> pares;//Ordeno por tiempo de salida los valores una vez terminado el proceso
        timer = cont = pos2 = 0;
        pos1 = n - 1;

        while(n > cont){
            cont2 = 0;
            while(cont2 < k){
                pos1 = (pos1 + 1) % n;
                if(v[pos1].first == -1){
                    cont2++;
                }
            }
            cont2 = 0;
            while(cont2 < m){
                pos2--;
                if(pos2 < 0) pos2 += n;
                if(v[pos2].first == -1){
                    cont2++;
                }
            }

            if(pos1 == pos2){
                v[pos1] = make_pair(timer++, 3);
                cont++;
            }
            else{
                v[pos1] = make_pair(timer, 1); //True para distinguir que fue el policia antihorario
                v[pos2] = make_pair(timer++, 2);
                cont += 2;
            }
        }

        for(int i = 0; i < n; i++){
            if(v[i].second == 1)
                pares[v[i].first].first = (i + 1);
            else if(v[i].second == 2)
                pares[v[i].first].second = (i + 1);
            else
                pares[v[i].first] = make_pair(i + 1, -1);
        }

        for(auto i: pares){
            if(i.second.second != -1)
                cout << setfill(' ') << setw(3) << i.second.first << setw(3) << i.second.second << (i == *prev(pares.end()) ? "": ",");
            else
                cout << setfill(' ') << setw(3) << i.second.first << (i == *prev(pares.end()) ? "": ",");
        }

        cout << endl;
    }

    return 0;
}