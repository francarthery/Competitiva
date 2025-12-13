#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '[';
    for(auto c : v) cout << c << ',';
    cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, q, x;
    cin >> n >> q;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    reverse(all(v));

    forn(i, q){
        cin >> x;
        
        for(int j = n - 1; j >= 0; j--){
            if(v[j] == x){
                v.erase(v.begin() + j);
                cout << n - j << ' ';
                break;
            }
        }
        v.push_back(x);
    }

    cout << '\n';
    
    return 0;
}