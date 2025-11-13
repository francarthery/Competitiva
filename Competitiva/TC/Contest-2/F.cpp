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
        freopen("output.out", "w", stdout);
    #endif

    ll t, n, x, k, tot;
    cin >> t;
    while(t--){
        cin >> n >> k;
        tot = 0;
        vector<int> pos, neg;
        forn(i, n){
            cin >> x;
            if(x >= 0) pos.pb(x);
            else neg.pb(abs(x));
        }

        sort(all(pos));
        sort(all(neg));
        tot -= max(abs((neg.empty() ? 0 : neg.back())), (pos.empty() ? INT_MIN : pos.back()));

        ll aux;

        if(!pos.empty()){
           for(int i = sz(pos) - 1; i >= 0; i -= k) tot += pos[i] * 2;
        }
        
        if(!neg.empty()){
            for(int i = sz(neg) - 1; i >= 0; i -= k) tot += neg[i] * 2;
        }

        cout << tot << '\n';
    }
    
    return 0;
}