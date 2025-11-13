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

    int t, n, m, v;
    cin >> t;
    while(t--){
        cin >> n >> m >> v;
        vector<int> v0(n), v1(n), v2(n);
        forn(i, n) cin >> v0[i];

        ll sum = v0[0], ma = 0;
        if(v0[0] >= v) v1[0] = 1, sum = 0, ma = 1;
        forr(i, 1, n){
            sum += v0[i];
            if(sum >= v) {
                v1[i] = v1[i - 1] + 1;
                sum = 0;
                ma = max((int)ma, v1[i]);
            }
            else v1[i] = v1[i - 1];
        }

        sum = v0[n - 1];
        if(v0[n - 1] >= v) v2[n - 1] = 1, sum = 0;
        for(int i = n - 2; i >= 0; i--){
            sum += v0[i];
            if(sum >= v) {
                v2[i] = v2[i + 1] + 1;
                sum = 0;
            }
            else v2[i] = v2[i + 1];
        }

        //vdbg(v1); vdbg(v2); dbg(ma);

        if(ma >= m){
            int r = 0;
            sum = v0[0], ma = 0;
            forn(l, n){
                int cant = 0;
                if(l > 0) cant += v1[l - 1];
                if(r < n - 1) cant += v2[r + 1];

                while(r < n and cant >= m) {
                    ma = max(ma, sum);
                    
                    r++;
                    if(r < n){
                        sum += v0[r];
                        cant = 0;
                        if(l > 0) cant += v1[l - 1];
                        if(r < n - 1) cant += v2[r + 1];
                    }
                }
                sum -= v0[l];
            }
        }
        else ma = -1;
        cout << ma << '\n';
    }


    
    return 0;
}