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

    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> a1(n), b1(n);
        forn(i, n) cin >> a1[i];
        forn(i, n) cin >> b1[i];

        int xora = 0, xorb = 0;
        vector<int> a, b;
        auto f = [&](){
            forn(i, n) if(a[i] == b[i]){
                xorb ^= b[i];
                xora ^= a[i];
            }
            
            forn(i, n){
                if(a[i] == b[i]) continue;

                if(i % 2 == 0){
                    if(!xora) xora = 1;
                    else xorb ^= 1;
                }
                else if(i % 2 == 1){
                    if(!xorb) xorb = 1;
                    else xora ^= 1;
                }
            }
        };

        dfor(i, 25){
            a.clear();
            b.clear();
            xora = xorb = 0;
            forn(j, n){
                a.pb((bool)(a1[j] & (1ll << i)));
                b.pb((bool)(b1[j] & (1ll << i)));
            }
            f();
            //vdbg(a); vdbg(b);

            if(xora != xorb){
                if(xora > xorb) cout << "Ajisai\n";
                else cout << "Mai\n";
                break;
            }
        }

        if(xora == xorb) cout << "Tie\n";
    }



    return 0;
}