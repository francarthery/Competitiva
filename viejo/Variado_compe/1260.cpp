#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> m;
    string aux;
    int n, i = 0, cont;
    cin >> n;
    cin.ignore();

    while(i <= n){
        cont = 0;
        m.clear();
        while(getline(cin, aux) and aux != ""){
            m[aux]++;
            cont++;
        }
        if(!m.empty()){
            for(auto p : m)
                cout << p.first << fixed << setprecision(4) << " " << (double)p.second * 100 / cont << endl;
            if(i < n) cout << endl;
        }
        i++;
    }

    return 0;
}