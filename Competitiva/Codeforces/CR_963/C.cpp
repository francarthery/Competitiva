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

    int t, k, n;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        sort(all(v));

        int l = v.back(), r = v.back() + k - 1, dif, inter, sobra;
        forn(i, n - 1){
            dif = v.back() - v[i];
            inter = dif / k;
            sobra = k - (v.back() - (inter * k + v[i]));
            //cout << dif << ' ' << inter << ' ' << sobra << '\n';
            if(inter % 2 == 0) r = min(v.back() + sobra - 1, r); //El intervalo termina antes
            else l = max(l, v.back() + sobra);
            if(r < l) break;
        }
        cout << (r < l ? -1 : l) << '\n';
    }
    
    return 0;
}