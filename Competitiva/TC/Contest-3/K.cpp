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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, x, pos1 = 0, pos2 = 0, rta = 0;
    cin >> n;

    vector<ii> v(2 * n);
    forn(i, 2 * n){
        cin >> x;
        v[i] = {x, i};
    }

    sort(all(v));
    forn(i, n){
        if(abs(v[2 * i].sc - pos1) + abs(v[2 * i + 1].sc - pos2) < abs(v[2 * i + 1].sc - pos1) + abs(v[2 * i].sc - pos2)){
            rta += abs(v[2 * i].sc - pos1);
            pos1 = v[2 * i].sc;
            rta += abs(v[2 * i + 1].sc - pos2);
            pos2 = v[2 * i + 1].sc;
        }
        else{
            rta += abs(v[2 * i].sc - pos2);
            pos2 = v[2 * i].sc;
            rta += abs(v[2 * i + 1].sc - pos1);
            pos1 = v[2 * i + 1].sc;
        }
        
    }

    cout << rta << '\n';
    
    return 0;
}