#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
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

    ll r; cin >> r;
    ll n; cin >> n;
	ll x;
    ll izq = 0, der = r;
    bool flag = false;

    forn(i, n){
        if(izq == der){
			flag = true;
		}
        cin >> x;
        izq += x;
        izq = min(izq, r);
        izq = max(izq, 0LL);
        der += x;
        der = min(der, r);
        der = max(der, 0LL);
    }
    if(flag) cout << izq << '\n';
    else cout << "uncertain\n";
    return 0;
}
