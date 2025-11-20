#include <bits/stdc++.h>

using namespace std;

int n, x, tot = 0;
vector<int> v(5);

void solve(int a, int b){
    if(v[a] and v[b]){ // "b b a" o "a a a b"
        x = min(v[a] * 2, v[b]) / 2;
        tot += x;
        v[a] -= x;
        v[b] -= x * 2;
        
        if(v[a] >= 3 and v[b] >= 1){
            x = min(v[a], v[b] * 3) / 3;
            tot += x;
            v[a] -= x * 3;
            v[b] -= x;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        v[x % 5]++;
    }

    tot += v[0];
    x = min(v[1], v[4]);
    tot += x;
    v[1] -= x; v[4] -= x;

    x = min(v[2], v[3]);
    tot += x;
    v[2] -= x; v[3] -= x;

    solve(1, 2);
    solve(3, 1);
    solve(2, 4);
    solve(4, 3);

    if(v[1] >= 5) tot += v[1] / 5;
    if(v[2] >= 5) tot += v[2] / 5;
    if(v[3] >= 5) tot += v[3] / 5;
    if(v[4] >= 5) tot += v[4] / 5;

    cout << tot << '\n';

    return 0;
}