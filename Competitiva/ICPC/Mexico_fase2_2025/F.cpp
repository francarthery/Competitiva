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

    int n; cin >> n;
    vector<int> v1(n), v2(n);
    map<int, int> m;
    forn(i, n) {
        cin >> v1[i] >> v2[i];
        if(v2[i]) m[i] = v2[i];
    }

    ll sum = accumulate(all(v2), 0ll);

    ll ans = 0;
    forn(i, n){
        ll sump = sum;
        if(m.count(i)) sump -= m[i];

        if(!sump) ans += v1[i];
        else if(sump < v1[i]) ans += sump - v1[i]; //me dio un poco la segunda
        
        vector<int> ind;
        for(auto &j : m){    
            if(j.fr == i) continue;
            if(j.sc > sump) {
                j.sc -= v1[i];
                break; 
            }

        }

    }



    return 0;
}