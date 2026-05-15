#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) cout<<"["; for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

map<ll,ll> compr;
vector<ll> decompr;

typedef ii tipo;
const ll inf = 2e18;
const ii neutro = {-inf, -inf};
tipo o(const tipo &a, const tipo &b) {return max(a,b);}
struct ST{
    int sz;
    vector<tipo>t;
    ST(int n){
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2*sz, neutro);
    }
    tipo &operator[](int p) {return t[sz+p];}
    tipo get(int i, int j) {return get(i,j,1,0,sz);}
    tipo get(int i, int j, int n, int a, int b){
        if(j <= a || b <= i) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a+b)/2;
        return o(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b)); 
    }
    void set(int p, tipo val){
        p+=sz;
        while(p>0 && t[p] != val){
            t[p] = val;
            p/=2;
            val = o(t[p*2], t[p*2+1]);
        }
    }
};

void compresion(vector<ll> v){
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int i = 0;
    for(auto &e : v){
        compr[e] = i;
        decompr[i] = e;
        i++;
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    int n;cin>>n;

    vector<ll> v(n);
    forn(i,n) cin>>v[i];
    decompr.resize(n);

    compresion(v);

    vector<vector<int>> reco(2,vector<int>(n,-1));
    const int MAYOR = 0, MENOR = 1;

    ST mn(n), my(n);

    dfor(i,n){

        // respuesta base
        {
            auto [actual, pos] = my[compr[v[i]]];
            if(actual < 1){
                my.set(compr[v[i]], {1,i});
            }
        }
        {
            auto [actual, pos] = mn[compr[v[i]]];
            if(actual < 1){
                mn.set(compr[v[i]], {1,i});
            }
        }

        // arranca como mayor
        {
            auto [mejor, pos] = mn.get(0, compr[v[i]]); // busco uno menor
            if(my[compr[v[i]]].first < mejor+1){        // guardo rta en arranca mayor
                my.set(compr[v[i]], {mejor+1, i});
                reco[MAYOR][i] = pos;
            }
        }
        
        // arranca como menor
        {
            auto [mejor, pos] = my.get(compr[v[i]]+1, n);   // busco uno mayor
            if(mn[compr[v[i]]].first < mejor+1){            //guardo rta en arranca menor
                mn.set(compr[v[i]], {mejor+1, i});
                reco[MENOR][i] = pos;
            }
        }

    }


    auto [k1, pos1] = mn.get(0,n);
    auto [k2, pos2] = my.get(0,n);

    int k, pos = -1, p;

    if(k1 > k2){
        k = k1;
        pos = pos1;
        p = MENOR;
    } else {
        k = k2;
        pos = pos2;
        p = MAYOR;
    }

    if(k < 3){
        cout<<0;nl;
        return 0;
    }

    cout<<k;nl;
    while(pos!=-1){
        cout<<pos<<" ";
        pos = reco[p][pos];
        p^=1;
    }nl;

    return 0;
}