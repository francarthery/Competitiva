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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), b(q), k(q);
    forn(i, n) cin >> a[i];
    forn(i, q) cin >> b[i] >> k[i];
    
    sort(all(a));
    
    forn(i, q){
        int lo = 0, hi = 2E8;
        while (lo < hi) {
            int x = (lo + hi) / 2; //Binaria sobre la distancia
            int l = b[i] - x;
            int r = b[i] + x;
            
            int cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l); //Tam intervalo con esa distancia

            if (cnt >= k[i]) hi = x;
            else lo = x + 1; 
        }
        cout << lo << "\n";
    }
    
    return 0;
}