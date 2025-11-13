#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n, m, k;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> m >> k;
        int k_max = n * ((double)(m - 1)/m);
        cout << (k_max > k ? "yes" : "no") << '\n';
    }

    return 0;
}
