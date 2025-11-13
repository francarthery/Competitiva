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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
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

    int n, k;
    float elem;
    while(cin >> n >> k){
        vector<int> v(n), res;
        for(int &i : v) cin >> i;

        forn(i, n) forn(j, i) forn(k, j) res.pb(v[i] + v[j] + v[k]);
        vector<int>::iterator it = res.end() - k;
        nth_element(res.begin(), it, res.end());
        elem = *it;
        //vdbg(res);
        cout << fixed << setprecision(1) << elem / 3.0 << '\n';
    }
    
    return 0;
}