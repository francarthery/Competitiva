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
        cin >> n >> m >> k;
        if(abs(n - m) > k or k > max(n, m)) cout << -1 << '\n';
        else{
            int n2 = n, m2 = m, cont = 0;
            bool beg = n > m;
            forn(i, n + m){
                if(!m2 or !n2) break;
                if(beg) {
                    cout << 0;
                    n2--;
                }
                else {
                    cout << 1;
                    m2--;
                }
                
                cont++;
                if(cont == k) cont = 0, beg = !beg;
            }
            while(n2--) cout << 0;
            while(m2--) cout << 1;
            cout << '\n';
        }
    }


    
    return 0;
}