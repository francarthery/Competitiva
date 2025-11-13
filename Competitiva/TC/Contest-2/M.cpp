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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<vector<int>, int> vi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n, m, x;
        cin >> n >> m;
        bool flag = true;
        vector<vi> v(m);
        vector<int> cant(n + 1, (m + 1) / 2), rta(m);

        forn(i, m){
            cin >> x;
            v[i].sc = i;
            v[i].fr.resize(x);
            forn(j, x) cin >> v[i].fr[j];
        }
        sort(all(v), [](vi &a, vi &b){return a.fr.size() < b.fr.size();});

        forn(i, m){
            if(cant[v[i].fr[0]] > 0){
                cant[v[i].fr[0]]--;
                rta[v[i].sc] = v[i].fr[0];
            }
            else{
                if(v[i].fr.size() > 1 and cant[v[i].fr[1]] > 0){
                    cant[v[i].fr[1]]--;
                    rta[v[i].sc] = v[i].fr[1];
                }
                else flag = false;
            }
        }

        if(flag){
            cout << "YES\n";
            forn(i, m) cout << rta[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }

    return 0;
}