#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<< "\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const ll inf = 2e18;
struct P{
    ll x, y;
    void lee(){
        cin>>x>>y;
    }
    ll operator * (const P & b) const {
        return x*b.x + y*b.y;
    } 
    P operator + (const P & b) const {
        return P{x+b.x, y+b.y};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w", stdout);
    #endif
    
    int n; cin >> n;
    map<string, pair<ll, P>> m; //palabra, .first = indice, .second.first = x, .second.second = y
    forn(i, n){
        string s; cin >> s;
        P p; p.lee();
        m[s] = {i,p};
    }

    int t; cin >> t;
    vector<string> text(t);
    forn(i, t) cin >> text[i];

    int q, k; cin >> q >> k;
    while(q--){
        int f; cin >> f;
        vector<string> query(f);
        forn(i, f) cin >> query[i];

        string ganador;

        vector<string> candidatos;
        int aux = k;
        while(aux){
            int cont = f - aux;
            
            // forn(i, t){
            //     if(cont == f){
            //         candidatos.push_back(text[i]);
            //         cont = f - aux;
            //     }
            //     if(text[i] == query[cont]) cont++; 
            //     else cont = f - aux;
            // }

            forn(i, t - aux){ //+ 1?
                bool ok = true;
                int ind = i;
                forr(j, cont, f){
                    if(text[ind++] != query[j]) ok = false;
                }
                
                if(ok){
                    candidatos.push_back(text[ind]);
                    //dbg(text[ind]);
                }
            }

            if(candidatos.size()) break;

            aux--;
        }

        //vdbg(candidatos);
        P sp{0,0};
        for(auto &s : candidatos){
            P p{0,0};
            if(m.count(s)){
                p = m[s].second;
            }
            sp = sp + p;
        }

        pair<ll,ll> mx = {-inf, -inf};
        for(auto &[s,par] : m){
            auto &[i, p] = par;
            pair<ll,ll> x;
            x = {p*sp, -i};
            if(x > mx) {
                mx = x;
                ganador = s;
            }
        }

        // dbg(ganador);
        forn(i, f) cout << query[i] << ' ';
        cout << (!aux ? "*" : ganador) << '\n';
    }

}