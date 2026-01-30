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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
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

    const int MAXN = 1e7 + 1;
    vector<int> duo(MAXN, -1);
    for(int i = 0; i * i < MAXN; i++) for(int j = i; j * j + i * i < MAXN; j++) duo[i*i + j*j] = i;

    array<int, 3> sol;
    auto check = [&](int x) {
        for(int i = 0; i*i <= x; i++) {
            if(duo[x - i*i] != -1) {
                sol = {i, duo[x - i*i], (int)(sqrt(x - i*i - duo[x - i*i] * duo[x - i*i]))};
                return true;    
            }
        }
        return false;
    };

    int t; cin >> t;
    //vector<int> v(1000);
    while(t--) {
        int n; cin >> n;
        int magia = -1; //Optimizacion intecesaria basada en observacion
        for(int i = 0; i <= MAXN; i += (1 << max(0, magia++))) if(check(n - i * i)){ 
            cout << i << ' ' << sol[0] << ' ' << sol[1] << ' ' << sol[2] << '\n';
            break;
        }
    }

    return 0;
}