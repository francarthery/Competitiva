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

    int t;
    string s, c;
    cin >> t;
    while(t--){
        int n, m, prim = 0, ult;
        cin >> n >> m;
        cin >> s;
        vector<int> ind(m), cache(m, 1);
        forn(i, m) cin >> ind[i];
        cin >> c;
        sort(all(ind), greater<int>());
        sort(all(c));
        forr(i, 1, m) if(ind[i - 1] == ind[i]) cache[i] = cache[i - 1] + 1;

        while(!cache.empty()){
            forn(i, cache.back() - 1) c.pop_back(); //Borro los cache - 1 elementos mayores
            s[ind.back() - 1] = c[prim]; //Coloco el menor
            prim++;
            ult = cache.back();
            forn(i, ult) {
                cache.pop_back();
                ind.pop_back();
            }
        }
        
        cout << s << '\n';
    }
    
    return 0;
}