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

int t, n, k;

void f(int n, vector<int> &v){
    int pot = (1 << (int)(log2(n)));
    int tam0 = 2 * pot - n;

    if(pot == n) v = vector<int>(n, k); //Todos k
    else{
        vector<int> aux((n - tam0) / 2);
        f((n - tam0) / 2, aux);
        forn(i, sz(aux)) v[i] = v[i + tam0 + sz(aux)] = aux[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> v(n);

        f(n, v);
        forn(i, n) cout << v[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}