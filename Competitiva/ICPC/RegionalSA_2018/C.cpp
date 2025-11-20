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

    int k, n; cin >> k >> n;
    vector<int> v(n);
    vector<int> m(k + 1);
    forn(i, n) {
        cin >> v[i];
        m[v[i]]++;
    }

    map<int, vector<int>> cants;
    forr(i, 1, k + 1) cants[m[i]].pb(i);

    if(sz(cants) == 2 and abs(cants.begin() -> fr - cants.rbegin() -> fr) == 1){
        if(sz(cants.begin() -> sc) == 1){
            cout << '+' << (cants.begin() -> sc).back() << '\n';
        }
        else if(sz(cants.rbegin() -> sc) == 1){
            cout << '-' << (cants.rbegin() -> sc).back() << '\n';
        }
        else cout << "*\n";
    }
    
    else if(sz(cants) == 3){
        if(abs(cants.begin() -> fr - cants.rbegin() -> fr) == 2 and sz(cants.begin() -> sc) == 1 and sz(cants.rbegin() -> sc) == 1){
            cout << '-' << (cants.rbegin() -> sc).back() << ' ' << '+' << (cants.begin() -> sc).back() << '\n';
        }
        else cout << "*\n";
    }
    else cout << "*\n";


    return 0;
}