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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int cont = 0;
    vector<int> v1(3), v2(3), v3(3);
    forn(i, 3) cin >> v1[i];
    forn(i, 3) cin >> v2[i];
    forn(i, 3) if(v1[i] > v2[i]) cont += ((v1[i] - v2[i]) / 2) * 2;
    forn(i, 3) if(v1[i] < v2[i]) cont -= (v2[i] - v1[i]) * 2;
    
    
    if(cont >= 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}