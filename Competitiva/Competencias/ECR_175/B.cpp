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

    ll t, k, x, n;
    cin >> t;
    while(t--){
        cin >> n >> x >> k;
        string s; cin >> s;
        ll cont = 0, mov = x, res = 0;
        bool flag = false;

        if(mov != 0){
            for(char &c : s){
                if(c == 'L') mov--;
                else mov++;

                cont++;
                if(mov == 0) {
                    flag = true;
                    break;
                }
            }
        }    

        if(cont <= k and flag){
            k -= cont;
            res = cont = 1;

            if(s[0] == 'L') mov = -1;
            else mov = 1;
            
            forr(i, 1, (sz(s))){
                if(s[i] == 'L') mov--;
                else mov++;

                cont++;
                if(mov == 0) {
                    res += k / cont;
                    break;
                }
            }

            cout << res << '\n';
        }
        else cout << 0 << '\n';
    }


    
    return 0;
}