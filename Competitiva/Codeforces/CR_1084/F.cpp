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
typedef tuple<int, int, int> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n, m, ind = 0; cin >> n >> m;
        vector<ii> v(n);
        forn(i, n) cin >> v[i].fr >> v[i].sc;
        sort(rall(v));
        map<int, vector<int>> pos; //numero, indices.

        ll bestSolo = 0; 
        vector<ll> best(n + 1);
        
        forn(i, n) {
            pos[v[i].sc].pb(i);
            if(v[i].sc == 0) {
                bestSolo = max(bestSolo, (ll)v[i].fr);
                v[i].fr = -1;
            }
        }

        ll borre1 = 0, borre2 = 0, sum1 = 0, sum2 = 0, it1 = -1, it2 = -1;

        auto jump = [&](ll &it, ll &sum) {
            if(it < n) it++;
            while(it < n and v[it].fr == -1) it++; 
            if(it < n) sum += v[it].fr;
        };

        bool prim = true;
        forr(i, 1, n + 1) {
            forn(j, borre1) jump(it1, sum1);
            forn(j, borre2) jump(it2, sum2);

            jump(it1, sum1);
            jump(it2, sum2);

            if(prim) {
                jump(it1, sum1); //El solo.
                prim = false;
            }

            bestSolo = max(bestSolo, sum1);
            best[i] = max(best[i - 1], sum2);

            borre1 = borre2 = 0;
            for(auto j : pos[i]) {
                if(j <= it1) sum1 -= v[j].fr, borre1++;
                if(j <= it2) sum2 -= v[j].fr, borre2++;
                v[j].fr = -1;
            }
        }

        forn(i, m) {
            ll a, b, ma = bestSolo;
            cin >> a >> b;
            if(!b) ma = max(ma, a);
            else ma = max(ma, best[b] + a);
            cout << ma << ' ';
        }
        cout << '\n';
    }



    return 0;
}