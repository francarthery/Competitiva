#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, mi = 2000000000, ma = 0;
    cin >> n;
    vector<int> pintura1(n), pintura2(n);

    for(int i=0; i < n; i++){
        cin >> pintura1[i];
    }
    for(int i=0; i < n; i++){
        cin >> pintura2[i];
    }

    sort(pintura1.begin(), pintura1.end(), greater<int>());
    sort(pintura2.begin(), pintura2.end());

    for(int i = 0; i < n; i++){
        ma = max(ma, pintura1[i] + pintura2[i]);
        mi = min(mi, pintura1[i] + pintura2[i]);
    }
    cout << ma - mi << '\n';

    return 0;
}