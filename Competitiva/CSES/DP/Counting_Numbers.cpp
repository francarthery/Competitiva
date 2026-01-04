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

//Esta dp es en general mas facil de hacer top down (recursiva) empezando desde el principio del numero y
//siendo el caso base el final del numero. 
//En las DPs de digitos se suele llevar un booleano tight que representa si en el prefijo que ya procesamos
// estabamos en el "techo" del numero. En esta dp tambien llevamos un booleano que nos dice si en el 
// prefijo ya procesado tenemos todos 0s para que la dp no los cuente como digitos iguales adyacentes (001 es valido)

string s;
ll dp[20][11][2][2];

ll solve(int pos, int ult, bool tight, bool cero){ //https://www.youtube.com/watch?v=qLHLsbD9emc
    if(pos == sz(s)) return 1;
    if(dp[pos][ult][tight][cero] != -1) return dp[pos][ult][tight][cero];

    dp[pos][ult][tight][cero] = 0;
    
    ll top = 10;
    if(tight) top = s[pos] - '0' + 1;
    forn(i, top) {
        bool tuco = tight && i == top - 1;
        if(i != ult or cero) dp[pos][ult][tight][cero] += solve(pos + 1, i, tuco, cero && i == 0);
    }

    return dp[pos][ult][tight][cero];
}

ll f(ll x){
    if(x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    ll rta = solve(0, 10, 1, 1);
    return rta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll a, b; cin >> a >> b;
    cout << f(b) - f(a - 1) << '\n';

    return 0;
}