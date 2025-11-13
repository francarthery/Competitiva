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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool lineales(ii &a, ii &b, ii &c){
    return(b.sc - a.sc) * (c.fr - a.fr) == (c.sc - a.sc) * (b.fr - a.fr);
}

bool f(vector<ii> &v, int k){
    if(sz(v) <= k) return true;
    if(!k) return false;

    forn(i, k){
        forr(j, i + 1, k + 1){

            vector<ii> aux;
            for(ii &p : v){
                if(!lineales(v[i], v[j], p)){
                    aux.pb(p);
                }
            }

            if(f(aux, k - 1)) return true;
        }
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<ii> v(n);
    for(auto &[a, b] : v) cin >> a >> b;

    cout << (f(v, 3) ? "possible" : "impossible") << '\n';

    
    return 0;
}