#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n, sum;
    cin >> t;

    while(t--){
        cin >> n;
        sum = 0;

        for(int i = 0; i < n; i++){
            sum += (i + 1) * (2 * i + 1);
        }

        cout << sum << ' ' << 2 * n << '\n';
        for(int i = n; i >= 1; i--){
            cout << 1 << ' ' << i;
            for(int j = 1; j <= n; j++) cout << ' ' << j;
            cout << '\n' << 2 << ' ' << i;
            for(int j = 1; j <= n; j++) cout << ' ' << j;
            cout << '\n';
        }
    }

    return 0;
}