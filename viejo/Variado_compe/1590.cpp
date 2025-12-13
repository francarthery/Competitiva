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
int t, n, k;
int ma = 0;
vector<int> v;

void f(int cont, int pos, int num){
    if(cont == k){
        ma = max(ma, num);
        return;
    }
    int aux;
    forr(i, pos, n) f(cont + 1, i + 1, num & v[i]);
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
        v.resize(n);
        forn(i, n) cin >> v[i];
        sort(all(v));
        ma = 0;
        f(0, 0, (1 << 30) - 1);

        cout << ma << '\n';
    }
    
    return 0;
}