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

    int n, q, x, d;
    cin >> n >> q;

    int k = 30; //2^k es la maxima distancia que puede tener un salto
    vector<vector<int>> sp(k, vector<int>(n)); //Cuidado: Nodos indexados en 0
    forn(i, n) {
        cin >> x;
        sp[0][i] = x - 1; //Es necesario definir los saltos de tam 1 (aristas originales)
    }

    forr(i, 1, k){
        for(int j = 0; j < n; j++){
            sp[i][j] = sp[i - 1][sp[i - 1][j]]; //Mi salto actual es dos saltos de la pot anterior
        }
    }

    function<void(int&, int)> query = [&](int &x, int d){ //hago un salto de tam d desde x
        while(d){
            x = sp[__builtin_ctz(d)][x];
            d &= (d - 1); //apago el ultimo bit
        }   
    };

    forn(i, q){
        cin >> x >> d;
        query(--x, d);
        cout << x + 1 << '\n';
    }

    return 0;
}