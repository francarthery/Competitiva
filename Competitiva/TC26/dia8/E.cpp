#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}



using namespace std;
typedef pair<int, int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int n, m; cin >> n >> m;
    set<tuple<int, int, int>> eventos;
    vector<tuple<int, int, int>> trenes(n);
    forn(i, n){
        int l, r, t; cin >> l >> r >> t;
        trenes[i] = {l, r, t};
        eventos.insert({l, i, 0});
        eventos.insert({r, i, 1});
    }

    vector<tuple<int, int, int>> personas(m);
    forn(i, m){
        int l, r, t; cin >> l >> r >> t;
        personas[i] = {l, r, t};
        eventos.insert({l, i + n, 2});
    }
    

    set<tuple<int, int, int>> trenesAbiertos; //recordar que aca va a ser r, t, indice

    vector<int> ans(m);
    for(auto [val, ind, tipo] : eventos){
        if(tipo == 0){
            trenesAbiertos.insert({get<1>(trenes[ind]), get<2>(trenes[ind]), ind});
        }else if(tipo == 1){
            trenesAbiertos.erase({get<1>(trenes[ind]), get<2>(trenes[ind]), ind});
        }else{
            auto it = trenesAbiertos.lower_bound({get<1>(personas[ind - n]), get<2>(personas[ind - n]), 0});
            if(it == trenesAbiertos.end()) ans[ind - n] = -1;
            else ans[ind - n] = get<2>(*it);
        }
    }

    forn(i, m) cout << ans[i] + (ans[i] != -1) << ' ';
    return 0;
}