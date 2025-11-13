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

    int t, n, m, k;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> a(n), b(m), pa(n / 2 + 1), pc(m / 2 + 1);
        forn(i, n) cin >> a[i];
        forn(i, m) cin >> b[i];

        sort(all(a)); sort(all(b));
        forn(i, n / 2) pa[i + 1] = pa[i] + (a[n - 1 - i] - a[i]);
        forn(i, m / 2) pc[i + 1] = pc[i] + (b[m - 1 - i] - b[i]);

        //vdbg(pa); vdbg(pc);

        if(n < m / 2) k = n;
        else if(m < n / 2) k = m;
        else k = (n + m) / 3;

        cout << k << '\n';

        forr(i, 1, k + 1){ //g(x, k - x)
            ll l = max(2*i - m, 0) - 1, r = min(i, n - i), mid; 

            while(r - l > 1){
                mid = (r + l) >> 1;
                if(pa[mid] + pc[i - mid] > pa[mid + 1] + pc[i - (mid + 1)]) r = mid;
                else l = mid;
            }
            
            cout << pa[l + 1] + pc[i - (l + 1)] << ' ';
        }
        
        cout << '\n';
    
    }


    
    return 0;
}