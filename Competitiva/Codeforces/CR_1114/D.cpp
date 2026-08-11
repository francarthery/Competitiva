#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> v(n);
        map<ll, ll> frec, mapeo;
        forn(i, n) {
            cin >> v[i];
            frec[v[i]]++;
        }

        ll ant = 0;
        bool ok = frec.count(0);
        forall(it, frec) {
            if(next(it) == frec.end()) mapeo[it -> first] = ant + 1;
            else {
                ll antant = ant;
                ll sig = next(it) -> first;
                ant = sig - it -> first;
                if(ant % it -> second) {
                    ok = false;
                    break;
                }
                else {
                    ant /= it -> second;
                    if(ant <= antant) ok = false;
                    mapeo[it->first] = ant;
                }
            }
        }

        if(!ok) cout << -1 << '\n';
        else {
            for(ll i : v) cout << mapeo[i] << ' ';
            cout << '\n';
        }
    }


    return 0;
}