#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> z;
string s, p, aux;
int n, r, m, rta = 0;

void zfunc(){
    int x = 0, y = 0, n = s.size();
    bool error;

    forr(i, 1, n){
        error = true;
        z[i] = (y < i) ? 0 : min(y - i + 1, z[i - x] - 1); //min(escenario 3, escenario 2)
        while(i + z[i] < n and (s[z[i]] == s[i + z[i]] or error) and z[i] < m){
            if(s[z[i]] != s[i + z[i]]) error = false;
            z[i]++;
        }
        if(i + z[i] - 1 > y){
            x = i; y = i + z[i] - 1;
        }
        if(z[i] == m) rta++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> s >> r >> m;

    aux.assign(m, 'a');
    s.insert(0, aux + '#');
    z.resize(s.size());
    
    forn(i, r){
        cin >> p;
        forn(i, m) s[i] = p[i];
        zfunc();
    }

    cout << rta << '\n';

    return 0;
}