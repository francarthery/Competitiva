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

    int n, x, aux, ini = -1, fin;
    bool flag = true, prim = true;
    cin >> n >> x;
    vector<int> v(n);
    list<int> l;
    forn(i, n) cin >> v[i];
    sort(all(v));
    if(x % 2 == 0) 
        forn(i, n){
            if(v[i] == x / 2){
                if(prim) {ini = i; prim = false;}
                fin = i;
            }
        }

    if(fin == ini or ini == -1){ // caso 1
        forr(i, 1, n){
            if(v[i] + v[i - 1] == x){
                if(v.front() != v[i - 1]) swap(v.front(), v[i - 1]);
                else if(v.back() != v[i]) swap(v.back(), v[i]);
                else flag = false;
                break;
            }
        }
    }
    else{ //tengo mas de dos que son x/2
        forn(i, ini) l.pb(v[i]);
        forr(i, fin, n) l.pb(v[i]);
        int cont = fin - ini;
        if(l.front() != x / 2){
            l.push_front(x / 2);
            cont--;
        } 
        auto it = ++l.begin(), f = l.end(); 
        while(cont and it != f){
            if(*it != x / 2 and *prev(it) != x / 2){
                l.insert(it, x / 2);
                cont--;
            }
            it++;
        }
        if(cont and *l.rbegin() != x / 2){
            l.pb(x / 2);
            cont--;
        }
        if(cont) flag = false;
    }
    
    if(!flag) cout << '*';
    else{
        if(l.empty()) for(int &i : v) cout << i << ' ';
        else for(int &i : l) cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}