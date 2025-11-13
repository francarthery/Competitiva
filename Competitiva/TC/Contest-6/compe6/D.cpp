#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;

//<key,mapped type,comparator,...>
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;


typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, m, q, x;
    cin >> n >> m >> q;
    vector<ii> v(m + 1);
    vector<pair<ll, ll>> que(q);
    vector<int> ans(q);
    forn(i, m + 1) v[i].sc = i;
    forn(i, n){
        cin >> x;
        v[x].fr++;
    }
    forn(i, q){
        cin >> x;
        que[i] = {x, i};
    }
    sort(all(que));
    sort(all(v));

    indexed_set elem;
    ll it = 1, r = n, l = 0, ant;

    forn(i, q){
        ll x = que[i].fr;
        if(sz(elem) < sz(v) - 1){ //Sigo teniendo elementos

            while(it < sz(v) and x > r){
                ant = v[it].fr;
                while(it < sz(v) and v[it].fr == ant) elem.insert(v[it++].sc);

                if(it <= m){
                    l = r;
                    r += (it - 1) * ((ll)v[it].fr - ant);
                }    
            }

            if(x <= r){
                int val = ((x - l) - 1) % sz(elem);
                ans[que[i].sc] = *elem.find_by_order(val);
                continue;
            }
        }

        ans[que[i].sc] = (x - r - 1) % m + 1;
    }

    forn(i, q) cout << ans[i] << '\n';

    return 0;
}