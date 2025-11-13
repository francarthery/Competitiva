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

    int n, c; cin >> n >> c;
    vector<int> v(2 * n);
    forn(i, n) cin >> v[i], v[i + n] = v[i];
    vector<ll> pre(2 * n + 1);

    forr(i, 1, 2 * n + 1) pre[i] = pre[i - 1] + v[i - 1];
    int k = 20; //2^k es la maxima distancia que puede tener un salto
    vector<vector<int>> sp(k, vector<int>(2 * n + 1)); //Precalculamos saltos de largo de potencias de 2 hasta k

    forn(i, 2 * n){
        int l = i, r = 2 * n;
        while(r - l > 1){
            int m = (r + l)/2;
            if(pre[m] - pre[i] >= c) r = m;
            else l = m;
        } 
        sp[0][i] = r;
    }
    sp[0][2 * n] = 2 * n;

    forr(i, 1, k){
        for(int j = 0; j < 2 * n + 1; j++){
            sp[i][j] = sp[i - 1][sp[i - 1][j]]; //Mi salto actual es dos saltos de la pot anterior
        }
    }

    function<int(int, int)> query = [&](int x, int d){
        while(d){
            x = sp[__builtin_ctz(d)][x];
            d &= (d - 1); //apago el ultimo bit
        }   
        return x;
    };
    
    forn(i, n){
        int l = 0, r = n;
        while(r - l > 1) {
            int m = (r + l) / 2;
            if(query(i, m) - i >= n) r = m;
            else l = m;
        }

        cout << l << (i < n - 1 ? ' ' : '\n');
    }

    return 0;
}