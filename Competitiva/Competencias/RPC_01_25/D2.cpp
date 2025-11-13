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
typedef pair<double, double> ii;

const int MAX = 505;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector<double> v(5), num{4, 6, 8, 12, 20}, res(MAX);
    forn(i, 5) cin >> v[i];
    forn(i, 5){
        if(v[i] > 0) {
            forn(j, num[i]) res[j + 1] = 1; //El primero del que tenga alguno
            v[i]--;
            break;
        }
    }

    forn(i, 5){
        if(v[i] > 0) {
            forn(j, v[i]) {
                vector<double> aux(MAX);

                forn(k, num[i]) forn(x, MAX - num[i]){
                    aux[k + 1 + x] += res[x];
                }
                //vdbg(aux);
                res = aux;
            }
        }
    }  

    vector<ii> ans;
    forn(i, sz(res)){
        if(res[i] != 0) ans.pb({res[i], i});
    }

    sort(rall(ans));
    for(ii &i : ans) cout << i.sc << ' ';
    
    
    return 0;
}