#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

int n, q;
vector<int> v;

bool f(int m){
    int ant = v[0], cont = 1;

    forr(i, 1, n){
        if(v[i] - ant < m) continue;
        else{
            ant = v[i];
            cont++;
        } 
    }
    return cont >= q;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    
    cin >> n >> q;
    v.resize(n);
    forn(i, n) cin >> v[i];

    sort(v.begin(), v.end());

    int l = 0, r = v[n - 1] + 10, m;
    while(l < r){
        m = (l + r) / 2;
        if(f(m)) l = m + 1;
        else r = m;
    }

    cout << r - 1 << '\n';

    return 0;
}