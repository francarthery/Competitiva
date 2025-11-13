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

    int n; cin >> n;
    map<int, int> gr;
    map<ii, int> flip;
    int a, b, inv = 0;

    forn(i, n - 1){
        cin >> a >> b;
        gr[b]++;
        if(gr[b] > 1) inv++;
        flip[{min(a, b), max(a, b)}] = a < b; // 1 si a < b. 0 sino.
    }
    //for(auto i : flip) dbg(i.sc);

    int q; cin >> q;
    if(inv) cout << "NE\n";
    else cout << "DA\n";
    forn(i, q){
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(flip[{a, b}]){
            gr[b]--;
            gr[a]++;
            if(gr[b] == 1) inv--;
            if(gr[a] == 2) inv++;
        } 
        else{
            gr[a]--;
            gr[b]++;
            if(gr[a] == 1) inv--;
            if(gr[b] == 2) inv++;
        }
        flip[{a, b}] = !flip[{a, b}];
        
        if(inv) cout << "NE\n";
        else cout << "DA\n";
        //for(auto i : gr) cout << i.fr << ' ' << i.sc << '\n';
    }

    return 0;
}