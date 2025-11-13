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

bool cuad(ll n){
    __int128_t l = 0, r = n;
    while(r - l > 1){
        __int128_t m = (l + r) / 2;
        if(m * m < n) l = m;
        else r = m; 
    }
    return r * r == n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1) cout << -1 << '\n';
        else{
            ll sum = ((ll)n * (n + 1)) / 2;

            if(cuad(sum)) cout << -1 << '\n'; //Suma cuadrado     
            else{
                vector<int> ans;
                forn(i, n) ans.pb(i + 1);
                
                bool flag;
                do{
                    flag = false;
                    random_shuffle(all(ans));
                    ll sum = 0;
                    forn(i, n){
                        sum += ans[i];
                        if(cuad(sum)) {
                            flag = true;
                            break;
                        }
                    }
                }
                while(flag);

                for(int i : ans) cout << i << ' ';
                cout << '\n';
            }  
        }
    }


    
    return 0;
}