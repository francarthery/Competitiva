#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, d, x, max_d = 0;
    char guion, c;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> d;
        vector<pair<int, char>> v;

        v.push_back({0, 'B'}); //Tomamos el las costas como dos piedras grandes
        for(int j = 0; j < n; j++){
            cin >> c >> guion >> x; //Probe con getline(cin, string, '-') pero daba 5% error
            v.push_back({x, c});
        }
        v.push_back({d, 'B'});
        
        max_d = 0;
        int cont = 0;
        while(v.size() - 1 > cont){
            
            if(cont < v.size() - 1 and v[cont].second == 'S' and v[cont + 1].second == 'S'){ //Si hay dos seguidas chicas evito pasar por la segunda
                max_d = max(max_d, v[cont + 2].first - v[cont].first);
                v[cont].second = 'X';
                cont += 2;
            }
            else{
                max_d = max(max_d, v[cont + 1].first - v[cont].first);
                if(v[cont].second == 'S') v[cont].second = 'X';
                cont++;
            }
        }
        
        pair<int, char> ant = v[0];
        for(int i = 1; i < v.size(); i++){
            if(v[i].second != 'X'){
                max_d = max(max_d, v[i].first - ant.first);
                ant = v[i];
            }
        }

        cout << "Case " << i + 1 << ": " << max_d << '\n';
    }

    return 0;
}