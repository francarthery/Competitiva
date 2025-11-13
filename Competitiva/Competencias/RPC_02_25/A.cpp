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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
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

    int n, m, r;
    cin >> n >> m >> r;

    string s, pal;
    vector<vector<int>> v(n);
    forn(i, n){
        cin >> s;
        forn(j, m){
            if(s[j] == 'P') v[i].pb(j);
        }
        reverse(all(v[i]));
    }

    while(cin >> pal){
        if(pal[0] == 'O') continue;

        while(v.back().empty()) v.pop_back();

        bool gano = false;
        int mov = 0;
        if(pal[3] == 'y') {
            gano = true;
            mov = sz(pal) - 9;
        }

        v.back().pop_back(); //Saco el de ma a la izquierda de abajo.
        
        if(gano){
            forn(i, mov){
                swap(v[sz(v) - 1 - i], v[sz(v) - 2 - i]);
                if(sz(v) - i == r) r--;
                else if(sz(v) - 1 - i == r) r++;
            }
        }
    }

    cout << r << '\n';
    
    return 0;
}