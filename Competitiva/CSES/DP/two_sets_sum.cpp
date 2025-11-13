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

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    if(((n * (n + 1)) / 2) & 1) cout << 0 << '\n';
    else{
        int tam = (n * (n + 1)) / 4 + 1;
        vector<int> v(tam);

        v[0] = 1;
        forr(i, 1, n + 1){
            for(int j = tam - i - 1; j >= 0; j--){
                v[j + i] += v[j];
                v[j + i] %= MOD;
            }
        }

        cout << ll(v[tam - 1]) * 500000004 % MOD << '\n';
    }
    
    
    return 0;
}