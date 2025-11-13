#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, dist, cont1 = 0, cont2;

    cin >> n >> k;
    cin.ignore();

    vector<string> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    dist = n % k;

    for(int i = 0; i < k; i++){
        cont2 = 0;
        for(int j = 0; j < n / k; j++){
            cout << v[cont1] << '\n';
            cont1++;
        }
        if(cont2++ < dist){
            cout << v[cont1++] << '\n';
        }

        if(i < k - 1) cout << '\n';
    }

    return 0;
}