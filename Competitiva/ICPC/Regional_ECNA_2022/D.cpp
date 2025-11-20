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

    string s; cin >> s;
    int q, l, r, n = sz(s); cin >> q;
    vector<int> prefa(n + 1), preft(n + 1), prefg(n + 1), prefc(n + 1);
    forn(i, n){
        if(s[i] == 'A') prefa[i + 1]++;
        else if(s[i] == 'T') preft[i + 1]++;
        else if(s[i] == 'G') prefg[i + 1]++;
        else if(s[i] == 'C') prefc[i + 1]++;

        prefa[i + 1] += prefa[i];
        preft[i + 1] += preft[i];
        prefg[i + 1] += prefg[i];
        prefc[i + 1] += prefc[i];
    }

    forn(i, q){
        cin >> l >> r;
        
        int conta = prefa[r] - prefa[l - 1];
        int contt = preft[r] - preft[l - 1];
        int contg = prefg[r] - prefg[l - 1];
        int contc = prefc[r] - prefc[l - 1];

        vector<tuple<int, int, char>> v{{conta, 4, 'A'}, {contt, 3, 'T'}, {contg, 2, 'G'}, {contc, 1, 'C'}};
        sort(rall(v));
        forn(i, 4){
            cout << get<2>(v[i]);
        }
        cout << '\n';
    }



    return 0;
}