#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(double i = 0; i < n; i++)
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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, c, l;

    cin >> n >> l >> c;
    vector<int> v(n);

    forn(i,n) cin >> v[i];

    sort(all(v));
    double ind = (double)n/l;
    int cont = 0;
    bool flag=true;
    forn(i,ind){

        cont += v[n-1-i*l];

    }
    if(cont > c) flag = false;
        
    cout << (flag ? 'S':'N');

    
    

    return 0;
}