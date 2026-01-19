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
    while(t--){
        int n; string s;
        cin >> n >> s;
        vector<int> sfc(n + 1), sfa(n + 1), sta;
        dfor(i, n){
            sfc[i] = sfc[i + 1];
            sfa[i] = sfa[i + 1];
            if(s[i] == '('){
                sfa[i]++;
                sta.pb(i);
            }
            else {
                sfc[i]++;
            }
        }

        int neto = 0, ma = -1;
        forn(i, n){
            if(s[i] == '(') neto++;
            else {
                while(sz(sta) and sta.back() < i) sta.pop_back();
                if(sta.empty()) break;
                int neto2 = neto + 1;
                int idx = sta.back() + 1;
                int ca = sfa[idx];
                int cc = sfc[idx];

                if(cc >= neto2) {
                    cc -= neto2;
                    ma = max(ma, i + 1 + neto2 + min(cc, ca) * 2);
                }

                neto--;
            }
        }

        cout << ma << '\n';
    }



    return 0;
}