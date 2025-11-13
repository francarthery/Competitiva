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
        vector<int> v1(n), v2(n);
        forn(i, n) cin >> v1[i];
        forn(i, n) cin >> v2[i];

        int exp = 2;
        forn(i, n - 1){
            if(v1[i + 1] >= v1[i] and v2[i + 1] >= v1[i] and v1[i + 1] >= v2[i] and v2[i + 1] >= v2[i]) exp = exp * 2 % 998244353;
        }

        cout << exp << '\n';
    }



    return 0;
}