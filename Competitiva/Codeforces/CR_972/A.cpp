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

    int t, n;
    vector<char> v{'a','e','i','o','u'};
    cin >> t;
    while(t--){
        cin >> n;
        string ans;
        int cant = n / 5;
        int mod = n % 5;
        forn(i, 5){
            if(i == 0){
                forn(j, cant) ans += v[i];
                if(mod > 0) ans += v[i];
            }
            if(i == 1){
                forn(j, cant) ans += v[i];
                if(mod > 1) ans += v[i];
            }if(i == 2){
                forn(j, cant) ans += v[i];
                if(mod > 2) ans += v[i];
            }if(i == 3){
                forn(j, cant) ans += v[i];
                if(mod > 3) ans += v[i];
            }
            if(i == 4){
                forn(j, cant) ans += v[i];
            }
        }

        cout << ans << '\n';
    }


    return 0;
}