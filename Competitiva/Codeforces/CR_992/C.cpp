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

ll exponente(int n){
    if(n > 41) return 1e13;
    else return (1ll << n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n < 41 and k > (1ll << (n - 1))) cout << "-1\n";
        else{
            vector<bool> reach(n + 1);
            
            ll resto = 2;
            ll p = exponente(n - min(n, resto));
            forn(i, n){
                while(k > p){
                    p += exponente(n - min(n, ++resto));
                }
                p -= exponente(n - resto);
                cout << resto - 1 << ' ';
                reach[resto - 1] = true;
                if(resto - 1 == n) break;
            }
            
            for(int i = n; i > 0; i--) if(!reach[i]) cout << i << ' ';
            cout << '\n';
        }
    }


    
    return 0;
}