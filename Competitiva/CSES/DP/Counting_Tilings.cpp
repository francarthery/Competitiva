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

    /* 
    Explicacion:
    Al ser n <= 10, podemos procesar fila a fila la grilla y llevar por cada fila con una bitmask
    las distintas formas en las que podrian sobresalir las tilings de 2x1 (Son maximo 2^n = 1024).
    Entonces, si nos encontramos en una fila i, y tenemos un patron j (determinado por la bitmask
    j) de espacios ya ocupados por tilings 2X1 de la fila anterior, sabemos que los distintos patrones
    que podemos usar para rellenar nuestra fila van a ser los que no se pisen con los elementos que
    ya tenemos ocupados y que puedan cubrir cada espacio de nuestra fila.
    Lo que podemos hacer para saber rapido cuales son las transiciones por cada posible patron es
    precomputarlas, ya que son las mismas transiciones para cada fila. Para hacerlo, iteramos
    todos los posibles pares de bitmasks (i, j), viendo si es valido transicionar de i a j ((2^n)^2 = 2^20).
    Es valido transicionar de una bitmask i a otra j si i no se pisa con j (i&j == 0)
    y si cuando junto i con j (i|j), los espacios que me quedan vacios son de largo par, para que 
    me entren tilings de 1X2.
    Ya con eso calculado lo unico que queda es ir fila por fila iterando todas las bitmasks posibles
    y de cada una, usando las transiciones ya calculadas, ver hacia donde podriamos ir en la fila i+1. 
    */

    int n, m; cin >> n >> m;
    const int MOD = 1e9+7;
    const int MAXN = (1 << n);

    vector<vector<int>> trans(MAXN);
    forn(i, MAXN) {
        forn(j, MAXN) {
            int pisan = (i & j);
            if(pisan) continue;
            int sum = (i | j);

            bool ok = true;
            int tam = 0;
            dfor(p, n) { //Miro si todos los espacios son de largo par
                if(sum & (1 << p)) {
                    if(tam % 2) ok = false;
                    tam = 0;
                }
                else tam++;
            }
            if(tam % 2) ok = false;
            if(ok) trans[i].pb(j); 
        }
    }
    
    vector<vector<int>> dp(m+1, vector<int>(MAXN));
    dp[0][0] = 1;

    forn(i, m) {
        forn(j, MAXN) {
            for(int k : trans[j]) dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % MOD;
        }
    }

    cout << dp[m][0] << '\n';


    return 0;
}