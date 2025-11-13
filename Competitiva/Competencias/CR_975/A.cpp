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
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        int mai = 0, mal = 0, rta;
        forn(i, n) 
            if(i % 2 == 0) mai = max(mai, v[i]);
            else mal = max(mal, v[i]);

        if(n % 2 == 0) rta = max(mal, mai) + n / 2;
        else rta = max(mai + (n + 1) / 2, mal + n / 2);
        
        cout << rta << '\n';
    }


    
    return 0;
}