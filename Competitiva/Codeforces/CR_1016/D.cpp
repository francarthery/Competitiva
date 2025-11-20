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

    ll t; cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;

        forn(i, q){
            string s; cin >> s;
            ll x, y;
            if(s == "<-"){
                cin >> x;
                ll posi = 0, posj = 0, cont = n - 1;
                ll l = 1, r = (1ll << (2 * n)) + 1;

                while(cont >= 0){
                    ll p1 = l + (r - l) / 4, p2 = l + (r - l) / 2, p3 = l + (r - l) / 2 + (r - l) / 4;
                    if(x < p1){
                        r = p1;
                    }
                    else if(x >= p1 and x < p2) {
                        posi += (1ll << cont);
                        posj += (1ll << cont);
                        l = p1;
                        r = p2;
                    }
                    else if(x >= p2 and x < p3) {
                        posi += (1ll << cont);
                        l = p2;
                        r = p3;
                    }
                    else if(x >= p3) {
                        posj += (1ll << cont);
                        l = p3;
                    }
                    cont--;
                }

                cout << posi + 1 << ' ' << posj + 1 << '\n';
            }
            else{
                cin >> x >> y;
                ll cont = n - 1, posx = 1, posy = 1;
                ll l = 1, r = (1ll << (2 * n)) + 1;
                while(r > l){
                    ll mx = (1ll << cont);
                    ll my = mx;
                    ll p1 = l + (r - l) / 4, p2 = l + (r - l) / 2, p3 = l + (r - l) / 2 + (r - l) / 4;

                    if(x >= posx + mx and y >= posy + my) {
                        posx += mx;
                        posy += my;
                        l = p1;
                        r = p2;
                    }
                    else if(x >= posx + mx){
                        posx += mx;
                        l = p2;
                        r = p3;
                    }
                    else if(y >= posy + my){
                        posy += my;
                        l = p3;
                    }
                    else{
                        r = p1;
                    }
                    cont--;
                }

                cout << r << '\n';
            }
        }
    }


    
    return 0;
}