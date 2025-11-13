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

    //https://codeforces.com/blog/entry/43440

    int n;
    cin >> n;
    vector<int> v(n + 1);
    forn(i, n) cin >> v[i];

    int lo = -1, hi = n - 1; // lo tiene que ser min - 1 y hi max (chequear)
    while (hi - lo > 1){
        int mid = (hi + lo)>>1;
        if (v[mid] > v[mid + 1]) hi = mid;
        else lo = mid; 
    }

    cout << v[lo + 1] << '\n';
    
    return 0;
}   