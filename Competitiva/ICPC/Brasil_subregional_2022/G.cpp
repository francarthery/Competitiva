#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<
using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

string s;
vector<ll> fibo;
vector<ii> ans; //posicion del fibonacci, cuantas veces
void solve(int posi, ll resto){
    if(resto == 1){
        forn(i, sz(ans)){
            forn(j, ans[i].second){
                forn(k, ans[i].first - 1){ //-1 ?
                    cout << "A";
                }
                cout << "B";
            }
            // dbg(ans[i].second);
            // dbg(ans[i].first);
            // dbg(fibo[ans[i].first]);
        }
        exit(0);
    }
    if(posi <= 1) return;

    if(fibo[posi] > resto or resto % fibo[posi]) return solve(posi - 1, resto);

    vector<ii> restos; //resto y la cantidad de veces que dividi
    ll aux = resto;
    int cont = 0;
    while(aux % fibo[posi] == 0){
        cont++;
        aux/= fibo[posi];
        restos.push_back({aux, cont});
    }
    reverse(all(restos));
    forn(i, sz(restos)){
        ans.push_back({posi, restos[i].second});
        solve(posi - 1, restos[i].first);
        ans.pop_back();
    }

    return solve(posi - 1, resto);
}

int probar(int posi){
    if(posi >= sz(s)) return 1;
    int rta = probar(posi + 1);
    if(s[posi] == 'A') rta+= probar(posi + 2);
    return rta;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif

    // string s; cin >> s;
    // cout << probar(0) << '\n';
    fibo.push_back(1);
    fibo.push_back(1);
    //cout << 144 * 7 << '\n';
    while(fibo.back() <= 1e15){
        fibo.push_back(fibo.back() + fibo[sz(fibo) - 2]);
    }
    //vdbg(fibo);
    ll n; cin >> n;
    solve(sz(fibo) - 1, n); //cambiar
    
    cout << "IMPOSSIBLE\n";

    return 0;
}