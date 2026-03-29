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
        vector<int> a(n), b(n);
        forn(i, n) cin >> a[i];

        bool flag = true;
        forn(i, n){
            cin >> b[i];
            if(b[i] < a[i]) flag = false;
        }

        map<int, int> mapi;
       
        forn(i, n){
            if(!mapi.count(b[i])) mapi[b[i]] = a[i];
            else if(mapi[b[i]] != a[i]) flag = false;
        }

        for(auto it = mapi.rbegin(); it != mapi.rend(); it++){
            auto it2 = next(it);
            if(it2 == mapi.rend()) break;
            if(it2 -> fr - it2 -> sc > it -> fr - it -> sc) flag = false;
            if(it2 -> sc > it -> sc) flag = false;
        }

        int ans = 0;

        for(auto [x, y] : mapi){
            ans = max(ans, x - y);
        }

        cout << (flag ? ans : -1) << '\n';
        
    }



    return 0;
}