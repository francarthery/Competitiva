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

    ll x; cin >> x;
    if((x & (x - 1)) == 0) {
        if(x == 1) cout << 1 << '\n';
        else cout << x - 1 << '\n';
    }
    else{
        ll res = (1ll << __lg(x)) + 1;
        //dbg(res);
        ll cont = __lg(x) - 1, cont2 = 1;
        while(cont > cont2){
            if(res + (1ll << cont) + (1ll << cont2) <= x) res += (1ll << cont) + (1ll<< cont2);
            cont--;
            cont2++;
        }
        if(cont == cont2 and res + (1ll << (cont2)) <= x) res += (1ll << (cont2));

        cout << res << '\n';
    }



    return 0;
}