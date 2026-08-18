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

    int n, q, a, b; cin >> n >> q;
    vector<int> v(n);
    map<int, int> compress;
    int cont = 0;
    forn(i, n) {
        cin >> v[i];
        if(compress.count(v[i])) v[i] = compress[v[i]];
        else v[i] = compress[v[i]] = cont++;
    }
    int k = sqrt(n);
    vector<array<int, 3>> qu(q);

    forn(i, q) {
        cin >> a >> b; a--; b--;
        qu[i] = {a, b, i};
    }

    sort(all(qu), [&](auto &a, auto &b) {
        int ba = a[0] / k;
        int bb = b[0] / k;
        if(ba != bb) return ba < bb;
        return (ba & 1) ? a[1] < b[1] : a[1] > b[1]; 
    });
 
    vector<int> count(cont), resp(q);
    int l = 0, r = -1, ans = 0;
    auto add = [&](int &x) {
        count[x]++;
        if(count[x] == 1) ans++;
    };

    auto del = [&](int &x) {
        count[x]--;
        if(count[x] == 0) ans--;
    };

    forn(i, q) {
        // cout << qu[i][0] << ' ' << qu[i][1] << ' ' << qu[i][2] << '\n';
        while(l > qu[i][0]) add(v[--l]);
        while(r < qu[i][1]) add(v[++r]); //asumo que r ya esta puesto. Arranco en -1? 
        while(l < qu[i][0]) del(v[l++]);
        while(r > qu[i][1]) del(v[r--]);
        resp[qu[i][2]] = ans;
    }

    for(int i : resp) cout << i << '\n';
    

    return 0;
}