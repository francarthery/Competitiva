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

    int n, x; cin >> n;
    vector<int> pos(n + 1);
    forn(i, n) {
        cin >> x;
        pos[x] = i;
    }
    
    int breaks = 1;
    forn(i, n - 1){
        if (pos[i + 1] > pos[i + 2]) breaks++; //cuento cuantas subsecuencias crecientes de elementos contiguos hay
    }

    cout << __lg(breaks) + ((1 << __lg(breaks)) == breaks ? 0 : 1) << '\n'; //hago log2 techo 

    return 0;
}