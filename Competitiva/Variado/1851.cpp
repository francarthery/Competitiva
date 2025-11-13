#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define fr first
#define sc second

using namespace std;

typedef unsigned long long ll;
typedef pair<long double, tuple<ll, ll, ll>> dii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll x, y, t = 1, ind = 1, rta = 0, cont = 1;
    vector<dii> v;
    priority_queue<dii> pq;
    while(cin >> x >> y){
        v.pb({((long double)y / x), {x, y, cont}});
        cont++;
    }

    t += get<0>(v[0].sc);

    forr(i, 1, sz(v)){
        while(pq.empty() or (ind < sz(v) and ind < t)){
            pq.push(v[ind]);
            ind++;
        }

        rta += get<1>(pq.top().sc) * (t - get<2>(pq.top().sc));
        t += get<0>(pq.top().sc);
        pq.pop();
    }

    cout << rta << '\n';

    return 0;
}