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
typedef pair<ll, ll> ii;

long double dist(ii &a, ii&b){
    return sqrtl((a.fr - b.fr) * (a.fr - b.fr) + (a.sc - b.sc) * (a.sc - b.sc));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, h, k, x, y, z; cin >> n >> h >> k;
    vector<ii> v(n);
    vector<int> tipo(n), estado(n, 1), vis(n, 0);
    map<ii, list<int>> mk, mh;

    forn(i, n){
        cin >> x >> y >> z;
        v[i] = {x, y};
        tipo[i] = z;
        if(z) mk[{x / k, y / k}].pb(i); //si es metal puedo ir solamente
        mh[{x / h, y / h}].pb(i);
    }

    cin >> x >> y;
    int ini;
    forn(i, n) {
        if(v[i] == ii(x, y)){
            ini = i;
            break;
        }
    }

    if(v[ini].sc == 0) { //Ya estoy
        cout << 0 << '\n';
        return 0;
    }

    vector<ii> mov{{0, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    int res = -1;
    queue<int> q;
    q.push(ini);
    estado[ini] = 0; 

    auto pepa = [&](list<int> &l, int &s, int &dmax){
        auto it = l.begin();
        while(it != l.end()){
            if(!estado[*it]){
                it = l.erase(it);
                continue;
            }
            if(dist(v[*it], v[s]) <= dmax) {
                estado[*it] = 0;
                q.push(*it);
                vis[*it] = vis[s] + 1;
                it = l.erase(it);
            }
            else it++;
        }
    };

    while(sz(q)){
        int s = q.front();
        q.pop();

        if(tipo[s] and abs(v[s].sc) <= h){ //Lo logre
            res = s;
            break;
        }

        forn(i, 9){
            int nx = v[s].fr / k + mov[i].fr, ny = v[s].sc / k + mov[i].sc;
            
            if(mk.count({nx, ny})){
                auto &l = mk[{nx, ny}];
                pepa(l, s, k);
            }

            nx = v[s].fr / h + mov[i].fr, ny = v[s].sc / h + mov[i].sc;
            if(tipo[s] and mh.count({nx, ny})){ //solo si estoy en h
                auto &l = mh[{nx, ny}];
                pepa(l, s, h);
            }
        }
    }

    if(res == -1) cout << -1 << '\n';
    else cout << vis[res] + 1 << '\n';


    return 0;
}