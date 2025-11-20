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
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    string pal;
    cin >> n >> m;
    vector<vector<string>> v(n, vector<string>(m));
    unordered_map<string, unordered_set<string>> mp;

    forn(i, n) forn(j, m) cin >> v[i][j];

    forn(i, m){
        mp[v[0][i]] = unordered_set<string>(); //Los nombres de la primera competencia son claves.
    }

    forr(i, 1, n){
        forn(j, m){
            if(mp.find(v[i][j]) == mp.end()){
                for(auto s : mp) s.second.insert(v[i][j]); //Si no es una clave es una opcion
            }
        }
        forn(j, m){
            auto it = mp.find(v[i][j]);
            if(it != mp.end()){
                forn(j, m){
                    it -> second.erase(v[i][j]); //Si el elemento es una clave, todos los de su competencia no pueden ser su pareja
                }
            }

            if(sz(it -> second) == 1){ // Ese elemento es la pareja oficial de it
                forall(s, mp){
                    if(s != it)
                        s -> second.erase(*(it -> second.begin())); //Como encontre la pareja de it, no es posibilidad del resto
                }
            }
        }
    }


    
    return 0;
}