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

    ll n, k, e, rta, derecha;

    cin >> n >> k >> e;

    vector<bool> v(n + 1);

    forr(i, 1, n + 1){
        if(i != k) v[i] = 1;
    }

    int l = e, r = n - e - k;
    int ma = max(l, r), mi = min(l, r);

    if(v[ma]){
        v[ma] = 0;
        ma = 0;
    }
   
    if(v[mi]){
        v[mi] = 0;
        mi = 0;
    }
   
    for(int i = ma; i >= 1; i--){
        if(v[i] and ma - i >= 0 and ma - i != i and v[ma - i]){
            v[i] = 0;
            v[ma - i] = 0;
            ma = 0;
        }
        if(ma == 0) break;
    }

    
    for(int i = mi; i >= 1; i--){
        if(v[i] and mi - i >= 0 and mi - i != i and v[mi - i]){
            v[i] = 0;
            v[mi - i] = 0;
            mi = 0;
        }
        if(mi == 0) break;
    }

    if(ma){
        for(int i = ma; i >= 1; i--){
            if(v[i] and ma - i >= 0){
                ma -= i;
                v[i] = 0;
            }
        }
    }

    if(mi){
        for(int i = mi; i >= 1; i--){
            if(v[i] and mi - i >= 0){
                mi-= i;
            }
        }
    }



    cout << ma + mi;
    
    return 0;
}