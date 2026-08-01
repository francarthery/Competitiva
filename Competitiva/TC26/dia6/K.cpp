#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

struct UnionFind{
    int nsets;
    vector<int> f, setsz;
    UnionFind(int n) : nsets(n), f(n,-1), setsz(n,1) {}
    int comp(int x) {
        return (f[x] == -1 ? x : f[x] = comp(f[x]));
    }
    bool join(int u, int v){
        int a = comp(u);
        int b = comp(v);
        if(a!=b){
            if(setsz[a] > setsz[b]) swap(a,b);
            f[a] = b;
            nsets--, setsz[b] += setsz[a];
        }
        return a==b;
    }
};

typedef long long tipo;
const tipo neutro = 0;
tipo oper(const tipo &a,const tipo &b){
    return max(a,b);
}
struct ST{
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1<<(32 - __builtin_clz(n));
        t = vector<tipo> (2*sz, neutro);
    }
    tipo &operator[](int p) {
        return t[sz+p];
    }
    void updall(){
        dfor(i,sz) t[i] = oper(t[2*i], t[2*i+1]);
    }
    tipo get(int i, int j){
        return get(i,j,1,0,sz);
    }
    tipo get(int i, int j, int n, int a, int b){
        if(j <= a || b <= i) return neutro;
        if(i <= a && b <= j) return t[n];
        int c = (a+b)/2;
        return oper(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
    }
    void set(int p, tipo val){
        p += sz;
        while(p>0 && t[p] != val){
            t[p] = val;
            p/=2;
            val = oper(t[p*2], t[p*2+1]);
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    vector<int> mx(n);
    iota(all(mx), 0);
    UnionFind comps(n);
    forn(i,m){
        int u,v;cin>>u>>v;
        u--,v--;
        if(u > v) swap(u,v);
        comps.join(u,v);
        mx[u] = max(mx[u], mx[v]);
    }
    int rta=0;
    int hasta = 0, unir = 0;
    forn(u,n){
        // dbg(u);
        // dbg(hasta);
        if(u < hasta){
            // dbg(u/nir);
            if(!comps.join(unir,u)) rta++;
        }
        else unir = u;
        hasta = max(hasta,mx[u] + 1);
        
        // nl;
    }

    cout<<rta<<endl;
    

    return 0;
}
