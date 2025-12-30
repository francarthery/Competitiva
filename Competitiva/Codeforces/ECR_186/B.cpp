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
        int a, b; cin >> a >> b;
        
        auto f = [&](bool flag) {
            int capas = 0, pot = 1;
            int a2 = a, b2 = b;
            while(1) {
                if(flag) {
                    a2 -= pot;
                    if(a2 >= 0) capas++;
                    else break;
                }
                else {
                    b2 -= pot;
                    if(b2 >= 0) capas++;
                    else break;
                }
                pot *= 2;
                flag = !flag;
            }
            return capas;
        };

        cout << max(f(0), f(1)) << '\n';;
    }



    return 0;
}