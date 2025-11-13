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
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    ll n, k, ini, largo, sum = 0, rta = 0;
    string s;
    bool unos = false;
    map<ll, ll> m;

    cin >> n >> k >> s;
    k = min(k,101475ll);
    forn(i, n){
        if(s[i] == '1' and unos) largo++;
        if(s[i] == '1' and !unos){
            largo = 1;
            unos = true;
        }
        
        if(s[i] == '0' and unos){
            m[largo]++;
            unos = false;
        }
    }
    if(unos) m[largo]++;

    for(auto i : m){
        sum += (((i.fr + 1) * (i.fr)) / 2) * i.sc;
    }
    

    while(sum > k){
        ll ma = (--m.end()) -> fr, cant = (--m.end()) -> sc;
        
        if(ma > 2){
            m[ma - 2]++;
            sum += ((ma - 1) * (ma - 2)) / 2;
        }
        if(ma > 1){
            m[1]++;
            sum++;
        }
        sum -= (((ma + 1) * ma) / 2);
        m[ma]--;
        if((--m.end()) -> second == 0) m.erase(--m.end());
        rta++;
    }

    cout << rta;

    
    return 0;
}