#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, x;
    while(cin >> n >> m){

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), greater<int>());

        for(int i = 0; i < m; i++){
            cin >> x;
            cout << v[x - 1] << '\n';
        }
    }
    
    return 0;
}