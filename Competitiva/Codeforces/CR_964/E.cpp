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
        int l, r; cin >> l >> r;
        
        ll cont = 0;
        int n = 1, exp = 1;

        while(n <= l) n *= 3, exp++;
        bool flag = n > r;
        cont += (min(n, r + 1) - l + 1) * (exp - 1);
    
        n *= 3, exp++;
        while(n <= r) {
            cont += (n / 3) * 2 * (exp - 1);
            n *= 3, exp++;
        }

        if(!flag) cont += (r - n / 3 + 1) * (exp - 1);
        
        cout << cont << '\n';        

    }

    return 0;
}