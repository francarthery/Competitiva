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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, pair<int, int>> iii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m, q;
    int k, a, b, x, y;

    cin >> n >> m >> q;

    vector<multiset<iii>> v(n);

    forn(i, m){
        cin >> k >> a >> b;
        v[b - a].insert({a, {b, k}});
    }

    forn(i, q){
        int flag = 0;
        cin >> x >> y;
        if(x > y) swap(x, y);
        
        auto it = v[y - x].begin();
        while(it -> fr <= x and it != v[y - x].end()){
            if(it -> fr + it -> sc.sc > x) flag++;
            it++;
        }

        cout << (flag % 2 ? "SI" : "NO") << '\n';
    }
    
    return 0;
}