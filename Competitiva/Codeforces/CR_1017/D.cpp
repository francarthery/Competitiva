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

    int t; cin >> t;
    while(t--){
        string p, s;
        cin >> p >> s;
        vector<ii> interp, inters;

        char ant = p[0];
        int largo = 1;
        forr(i, 1, sz(p)){
            if(p[i] == ant) largo++;
            else {
                interp.pb({ant, largo});
                largo = 1;
            }
            ant = p[i];
        }
        interp.pb({ant, largo});

        ant = s[0];
        largo = 1;
        forr(i, 1, sz(s)){
            if(s[i] == ant) largo++;
            else {
                inters.pb({ant, largo});
                largo = 1;
            }
            ant = s[i];
        }
        inters.pb({ant, largo});

        //forn(i, sz(interp)) cout << interp[i].fr << ' ' << interp[i].sc << '\n';
        //forn(i, sz(inters)) cout << inters[i].fr << ' ' << inters[i].sc << '\n';
        
        bool flag = true;
        if(sz(interp) != sz(inters)) cout << "NO\n";
        else{
            forn(i, sz(interp)){
                if(interp[i].fr == inters[i].fr and interp[i].sc <= inters[i].sc and inters[i].sc <= 2 * interp[i].sc) continue;
                else{
                    flag = false;
                }
            }
            cout << (flag ? "YES" : "NO") << '\n';
        }
    }



    return 0;
}