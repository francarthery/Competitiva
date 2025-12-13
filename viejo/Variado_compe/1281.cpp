#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, p, cant;
    float pr, rta;
    string item;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> m;
        rta = 0;
        unordered_map<string, float> mp;

        for(int j = 0; j < m; j++){
            cin >> item >> pr;
            mp[item] = pr;
        }

        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> item >> cant;
            rta += mp[item] * cant;
        }

        cout << fixed << setprecision(2) << "R$ " << rta << '\n';
            
    }

    return 0;
}