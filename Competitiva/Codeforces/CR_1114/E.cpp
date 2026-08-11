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
        vector<ll> v(n), pos;
        multiset<ll> neg;
        int ceros = 0;
        forn(i, n) {
            cin >> v[i];
            if(v[i] > 0) pos.push_back(v[i]);
            else if(v[i] < 0) neg.insert(-v[i]);
            else ceros++;
        }
        sort(all(pos));

        if(pos.empty()) {
            cout << -1 << '\n';
            continue;
        }
        bool ok = true;
        int ipos = 1;
        ll elem = pos[0];
        vector<ll> ans{elem};
        while(ipos < sz(pos) or sz(neg) or ceros) {
            auto indneg = neg.upper_bound(elem-1);
            if(indneg != neg.begin()) {
                elem -= *prev(indneg);
                neg.erase(prev(indneg));
            }
            else {
                if(ceros) ceros--;
                else if(ipos < sz(pos)) elem += pos[ipos++];
                else if(sz(neg)) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(elem);
        }

        if(!ok) cout << -1;
        else for(auto i : ans) cout << i << ' '; 
        cout << '\n';
    }


    return 0;
}