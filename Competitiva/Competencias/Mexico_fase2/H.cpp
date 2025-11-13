#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x, y; cin >> n >> x >> y;

    indexed_set s;

    forr(i, 1, n + 1) s.insert(i);
    int ind1 = 0, ind2 = n - 1;
    x--; y--;

    vector<int> ans;
    while(sz(s) > 2){
        ind1 = (ind1 + x) % sz(s);
        ind2 = ((ind2 - y) % sz(s) + sz(s)) % sz(s);

        if(ind1 == ind2){
            ans.pb(*s.find_by_order(ind1));
            s.erase(s.find_by_order(ind1));
            if(ind1 == sz(s)) ind1 = 0;
            ind2 = (ind2 - 1 + sz(s)) % sz(s);
        }
        else{
            int borro1 = *s.find_by_order(ind1);
            int borro2 = *s.find_by_order(ind2);
            s.erase(borro1);
            s.erase(borro2);
            if(ind1 > ind2){
                ind1 = (ind1 - 1 + sz(s)) % sz(s);
                ind2 = (ind2 - 1 + sz(s)) % sz(s);
            }else{
                ind2 = (ind2 - 2 + sz(s)) % sz(s);
            }
        }
    }

    while(sz(s)){
        ans.pb(*s.find_by_order(0));
        s.erase(s.find_by_order(0));
    }

    sort(all(ans));
    forn(i, sz(ans)) cout << ans[i] << ' ';

    
    return 0;
}
