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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        ll sum = 0, mi = 1e9;
        forn(i, n) {
            cin >> v[i];
            sum += v[i];
            mi = min(mi, (ll)v[i]);
        }

        ll l = 0, r = sum / n + 1; //binaria sobre multiplos cant elementos. Nunca puede ser 0
        while(r - l > 1){
            ll m = (l + r) / 2;
            vector<int> aux = v;

            bool flag = true;
            while(flag){ //log(1e9) mas o menos
                flag = false;
                forn(i, n){
                    ll sobra = aux[i] - m + 1;
                    if(sobra <= 0) continue;
                    if(sobra / 2) flag = true;
                    aux[i] -= (sobra - (sobra % 2));
                    aux[(i + 1) % n] += sobra / 2;
                }
            }   
            
            flag = true;
            forn(i, n) if(aux[i] != m) flag = false;

            if(!flag) r = m;
            else l = m;            
        }

        if(l == 0) cout << -1 << '\n';
        else cout << sum - n * l << '\n';
    }

    
    return 0;
}