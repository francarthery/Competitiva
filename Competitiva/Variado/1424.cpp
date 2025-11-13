#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, x, y;

    while(cin >> n >> m){
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            cin >> x;
            mp[x].push_back(i);
        }

        for(int i = 0; i < m; i++){
            cin >> x >> y;
            if(mp[y].size() >= x) cout << mp[y][x - 1] + 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}