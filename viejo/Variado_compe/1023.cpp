#include <bits/stdc++.h>

using namespace std;

//Prueba usando scanf

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x, y, cont = 1;
    map<int, int> m;
    while(cin >> n and n != 0){
        if(cont != 1) printf("\n");

        m.clear();
        int total = 0, pers = 0;

        for(int i = 0; i < n; i++){
            cin >> x >> y;
            m[y / x] += x;
            total += y;
            pers += x;
        }

        cout << "Cidade# " << cont << ":\n";
        cout << m.begin() -> second << "-" << m.begin() -> first;//Al principio no va espacio
        for(auto i = ++m.begin(); i != m.end(); i++){
            cout << " " << i->second << "-" << i->first;
        }
        cout << "\nConsumo medio: " << fixed << setprecision(2) << floor(100 * ((float)total/pers)) / 100.0 << " m3.\n";
        
        cont++;
    }

    return 0;
}