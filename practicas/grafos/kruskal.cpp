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
typedef long long ll;
typedef pair<int, int> ii;

int n;
vector<int> padre; //padre.resize(n)
vector<pair<int, ii>> v; //Lista de arcos ponderados

void init(){
    sort(all(v)); //Se ordenan de forma creciente por peso los arcos
    forn(i, n) padre[i] = i; //Incialmente cada nodo forma un grupo individual
}

int Find(int x){
    if(x == padre[x]) return x;  
    else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){ 
    int u = Find(x), v = Find(y);
    if(u != v){
        if(u < v) padre[u] = v;
        else padre[v] = u;
    }    
}

ll Kruskal(){
    ll a, b, sum = 0;
    init();

    forn(i, v.size()){
        a = Find(v[i].second.first);
        b = Find(v[i].second.second);
        if(a != b){ //Si los elementos de la arista no tienen el mismo padre, esta se usa.
            sum += (v[i].first); //Sumamos el peso de esta arista al arbol total
            Union(a, b);
        }
    }
    return sum;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int m, a, b, p;
    while(cin >> n >> m and n and m){
        padre.resize(n + 1); //Creamos array de tamaño n
        ll sum = 0;
        forn(i, m){
            cin >> a >> b >> p;
            v.pb({p, {a, b}});
            sum += p;
        }
        cout << sum - Kruskal() << '\n';
    }

    return 0;
}