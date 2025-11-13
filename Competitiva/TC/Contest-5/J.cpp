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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    cin >> s;
    char ant = '#';
    ll ini = 0, tam = 0, totv = 0;
    vector<ii> v;
    forn(i, sz(s)){
        if(ant != 'v' and s[i] == 'v'){
            ini = i;
            tam = 1;
        }
        else if(ant == 'v' and s[i] == 'v'){
            tam++;
        }
        else if(ant == 'v' and s[i] != 'v'){
            v.pb({totv + tam - 1, ini});
            totv += tam - 1;
        }
        ant = s[i];
    }

    if(ant == 'v' and tam > 1){
        v.pb({totv + tam - 1, ini});
        totv += tam - 1;
    }

    reverse(all(v));
    ll der = 0, rta = 0;
    forn(i, sz(s)){
        if(!v.empty() and v.back().sc < i){
            der = (ll)v.back().fr;
            v.pop_back();
        }
        if(s[i] == 'o') rta += der * (totv - der);
    }

    cout << rta << '\n';
    
    return 0;
}