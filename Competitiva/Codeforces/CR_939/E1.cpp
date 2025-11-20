#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n;

    cin >> t;

    while(t--){
        cin >> n;
        vector<int> v(n);
        bool s = true;

        for(int i=0; i < n; i++)cin >> v[i];

        while(s){
            s = false;
            for(int i=0; i < n-1; i++){
                int x = v[i+1];
                v[i+1] = max(0, v[i+1] - v[i]);
                if(v[i+1] != x) s = true;
            }
            int x = v[0];
                v[0] = max(0, v[0] - v[n-1]);
                if(v[0] != x) s = true;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            if(v[i] != 0) cout << v[i] << ' ';
        }cout << endl;

    }

    return 0;
}