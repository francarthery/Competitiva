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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//<key,mapped type,comparator,...>
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
// find_by_order(i) returns iterator to the i-th elemnt
// order_of_key(k): returns position of the lower bound of k (0-indexed)
// Ej: 12, 100, 505, 1000, 10000.
// order_of_key(10) == 0, order_of_key(100) == 1,
// order_of_key(707) == 3, order_of_key(9999999) == 5

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int q; cin >> q;
    indexed_set s;
    map<int, int> m;
    while(q--){
        int op; cin >> op;

        if(op == 3){
            if(!sz(s)) cout << "Empty!";
            else if(sz(s) % 2 == 0) cout << (s.find_by_order(sz(s)/2 - 1) -> fr + s.find_by_order(sz(s)/2) -> fr)/2;
            else cout << s.find_by_order(sz(s)/2) -> fr;
            cout << '\n';
        }else{ //inserto
            int x; cin >> x;
            if(op == 1){ //meto
                m[x]++;
                s.insert({x, m[x]});
            } 
            else{ //borro
                if(m.count(x)) s.erase(s.find({x, m[x]})), m[x]--;
            }
        }
    }





    return 0;
}