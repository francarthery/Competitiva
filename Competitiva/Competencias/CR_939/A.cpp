#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, k, q, x;
    cin >> t;

    while(t--){
        cin >> k >> q;
        vector<int> a(k);

        for(int i = 0; i < k; i++){
            cin >> a[i];
        }

        for(int i = 0; i < q; i++){
            cin >> x;
            if(x < a[0]) cout << x;
            else cout << a[0] - 1;
            if(i < q - 1) cout << ' ';
            else cout << '\n';
        }
    }

    return 0;
}