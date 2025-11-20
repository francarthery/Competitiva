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

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        forn(i, n) cin >> a[i];
        forn(i, m) cin >> b[i];
        sort(all(b));

        if(b[0] - a[0] < a[0]) a[0] = b[0] - a[0];

        bool flag = true;
        forr(i, 1, n){
            if(a[i] > a[i - 1]){ //Quiero acercarlo
                //elem = 2 * a[i] - (a[i] - a[i - 1])
                int elem = lower_bound(all(b), 2 * a[i] - (a[i] - a[i - 1])) - b.begin();
                if(elem < m and b[elem] - a[i] < a[i]) a[i] = b[elem] - a[i];
            }
            else if(a[i] < a[i - 1]){ //Quiero pasarme
                int elem = lower_bound(all(b), 2 * a[i] - (a[i] - a[i - 1])) - b.begin();
                if(elem < m) a[i] = b[elem] - a[i];
                else{
                    flag = false;
                    break;
                }
            }
        }

        forr(i, 1, n) if(a[i - 1] > a[i]) flag = false;

        cout << (flag ? "YES" : "NO") << '\n';
    }


    
    return 0;
}