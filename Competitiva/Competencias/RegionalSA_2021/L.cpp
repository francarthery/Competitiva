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

    int n, x, ma = 0;
    cin >> n >> x;
    vector<ii> v(n);
    for(auto &[x, y] : v) {
        cin >> x >> y;
        ma = max(ma, x + y);
    }
    vector<bool> inter(ma + 1);
    forn(i, n){
        forr(j, v.back().fr, v.back().fr + v.back().sc + 1){
            inter[j] = true;
        }
        v.pop_back();
    }
    //for(auto i: inter) cout << i << ' ';
    int mi = INT_MAX, ind = 0;
    forn(i, min(480, ma)){
        int val = 0;
        for(int j = i; j <= ma; j += x){
            val += inter[j];
        }
        if(val < mi){
            mi = val;
            ind = i;
        }
    }

    cout << ind << ' ' << mi << '\n';
    
    return 0;
}