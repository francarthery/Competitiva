#include <bits/stdc++.h>
#define forr(i, a, n) for(long long i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fst first
#define snd second

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
    
    int t;
    cin >> t;
    while(t--){
        long long x, y, z, k, rta = 0;
        cin >> x >> y >> z >> k;

        forr(i, 1, x + 1) forr(j, 1, y + 1){
            if(i * j > k) break;
            if(k % (i * j) == 0 and k / (i * j) <= z){
                rta = max(rta, (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
            }
        }

        cout << rta << '\n';
    }
    
    return 0;
}