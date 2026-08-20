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
typedef pair<int,int> ii;
 


typedef int tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b){
    return a+b;
}
struct ST{
    int sz;
    vector<tipo> t;
    ST(int n){
        sz = 1<<(32-__builtin_clz(n));
        t = vector<tipo>(2*sz, neutro);
    }
    tipo &operator[](int p) {return t[sz+p];}
    void updall(){
        dfor(i,sz) {
            t[i] = oper(t[2*i], t[2*i+1]);
        }
    }
    tipo get(int i, int j) {
        return get(i,j,1,0,sz);
    }
    tipo get(int i, int j, int n, int a, int b){
        if(j<=a || b <= i) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a+b)/2;
        return oper(get(i,j,2*n,a,c),get(i,j,n*2+1,c,b));
    }
    void set(int p, tipo val){
        p+=sz;
        while(p > 0 && t[p] != val){
            t[p] = val;
            p/=2;
            val = oper(t[2*p], t[2*p+1]);
        }
    }
};

const int N=3e5+5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif
    int y; cin>>y;
    int n; cin>>n;

    ST st(y+1);
    vector<int> ori(y);
    vector<vector<int>> ind(N);
    forn(i,y){
        int x;cin>>x;
        ori[i] = x;
        ind[x].push_back(i);
    }
    

    vector<tuple<int,int,int,bool,int>> gen(n);
    // posicion, [rango consulta), clasifico o no,indice rta
    forn(i,n){
        int a,p,f;cin>>a>>p>>f;
        gen[i] = {p,a,a+f,(ori[a-1] >= p),i};
    }
    sort(rall(gen));

    vector<int> rta(n);
    int ant=N;
    forn(i,n){
        auto [po, iz, de, cl, in] = gen[i];
        // cout<<iz ws po ws de-iz ws cl<<endl;
        if(cl){
            rta[in] = 0;
            continue;
        } 
        while(ant > 0 && ant > po){
            ant--;
            for(auto &indice : ind[ant]){
                // dbg(ant);
                st.set(indice,1);
            }
        }
        rta[in] = st.get(iz,de);
    }

    for(auto e : rta){cout<<e;nl;}

    return 0;
}