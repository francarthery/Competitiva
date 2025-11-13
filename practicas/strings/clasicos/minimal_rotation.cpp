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

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

const int a1 = 31, a2 = 23, b1 = 1e9 + 7, b2 = 1e9 + 9;
vector<pair<ll, ll>> p, h;

void Hash(string &s){ //Preprocesa hash en O(n)
    p.resize(s.size());
    h.resize(s.size());

    p[0] = {1, 1};
    h[0] = {s[0], s[0]};
    for(int i = 1; i < s.size(); i++) {
        h[i].fr = (h[i - 1].fr * a1 + s[i]) % b1;
        p[i].fr = (p[i - 1].fr * a1) % b1;
        h[i].sc = (h[i - 1].sc * a2 + s[i]) % b2;
        p[i].sc = (p[i - 1].sc * a2) % b2;
    }
}

ll gethash(int l, int r){ //Devuelve hash del substring [l...r]
    pair<ll, ll> hashval({h[r].fr, h[r].sc});
    if(l > 0){
        hashval.fr = ((hashval.fr - h[l - 1].fr * p[r - l + 1].fr) % b1 + b1) % b1;
        hashval.sc = ((hashval.sc - h[l - 1].sc * p[r - l + 1].sc) % b2 + b2) % b2;
    }
    return (hashval.fr << 32 | hashval.sc);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = sz(s), l, r, m, ini = 0;
    s += s;

    Hash(s);
    forr(i, 1, n){
        l = i, r = i + n - 1;
        while(l < r){
            m = (l + r + 1) / 2;
            if(gethash(i, m) != gethash(ini, ini + m - i)) r = m - 1;
            else l = m;
        }

        if(s[r] != s[ini + r - i] and s[r] < s[ini + r - i]) ini = i; //Todos los caracteres son distintos
        else if(s[r] == s[ini + r - i] and r < 2 * n - 1 and s[r + 1] < s[ini + r - i + 1]) ini = i; //Al menos 1 es igual
    }

    forr(i, ini, ini + n) cout << s[i];
    cout << '\n';
    
    return 0;
}