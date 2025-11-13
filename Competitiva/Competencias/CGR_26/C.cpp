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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    long long t, n, k;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        k = 0;

        forn(i, n) cin >> v[i];

        forn(i, n){
            long long j = i + 1, cont = k;
            while(j < n and cont >= k)
                cont += v[j++];

            if(cont < k) k += v[i];
            else k = abs(k + v[i]);
        }

        cout << abs(k) << '\n';
    }

    /*
    //Solucion roca tourist
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int64_t mn = 0;
        int64_t mx = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mn += a;
            mx += a;
            mx = max(mx, abs(mn));
        }
        cout << mx << '\n';
    }
    */
    
    return 0;
}