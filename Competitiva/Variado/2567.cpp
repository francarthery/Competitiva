#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, rta;
    while(cin >> n){
        vector<int> v(n);
        rta = 0;

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        auto ini = v.begin();
        auto fin = --v.end();

        for(int i = 0; i < n/2; i++){
            rta += *fin - *ini;
            ini++;
            fin--;
        }

        cout << rta << '\n';
    }

    return 0;
}