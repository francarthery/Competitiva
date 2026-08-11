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

    int n, q; cin >> n >> q;
    vector<int> v(n);
    map<int, int> compress;
    int cont = 0;
    forn(i, n) {
        cin >> v[i];
        if(compress.count(v[i])) v[i] = compress[v[i]];
        else v[i] = compress[v[i]] = cont++;
    }
    int k = sqrt(n);

    vector<vector<array<int, 3>>> queries(k+5);
    int a, b;
    forn(i, q) {
        cin >> a >> b; a--; b--;
        queries[a / k].push_back({b, a, i});
    }

    forn(i, sz(queries)) sort(all(queries[i]));
    vector<int> resp(q);
    forn(i, sz(queries)) {
        int ant = (i+1) * k;
        int ans = 0;
        vector<int> count(n);
        for(auto r : queries[i]) {
            forr(j, ant, r[0]+1) {
                count[v[j]]++;
                if(count[v[j]] == 1) ans++;
                ant++;
            }
            forr(j, r[1], min(r[0]+1, (i+1)*k)) {
                count[v[j]]++;
                if(count[v[j]] == 1) ans++;
            }
            resp[r[2]] = ans;

            forr(j, r[1], min(r[0]+1, (i+1)*k)) {
                count[v[j]]--;
                if(count[v[j]] == 0) ans--;
            }
        }
    }

    forn(i, q) cout << resp[i] << '\n';

    return 0;
}