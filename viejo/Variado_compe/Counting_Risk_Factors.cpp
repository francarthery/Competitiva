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

    string s;
    char c;
    int n, k, l;
    cin >> n >> k >> l >> s;
    vector<bool> v(26);
    forn(i, l){
        cin >> c;
        v[c - 'a'] = true;
    }

    int ini = 0, rta = 0;
    deque<int> vals;
    forn(i, s.size()){
        if(v[s[i] - 'a']) vals.pb(i);
        if(sz(vals) > k){
            rta += (vals.front() - ini + 1) * (i - vals[k - 1]);
            ini = vals.front() + 1;
            vals.pop_front();
        }
    }
    if(sz(vals) >= k) rta += (vals.front() - ini + 1) * (s.size() - vals.back());
    cout << rta << '\n';
    
    return 0;
}