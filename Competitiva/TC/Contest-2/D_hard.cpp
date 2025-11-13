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
typedef pair<pair<int, int>, int> ii;
typedef pair<double, ii> dii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    vector<vector<dii>> dp(n, vector<dii>(10, {-1, {{-1, -1}, 0}})); //Guardo: (log10(valor), ind_ant, ind_act)

    dp[0][v[0] % 10] = {log10(v[0]), {{-1, -1}, 0}}; //Pongo el primero
    forr(i, 1, n){
        forn(j, 10) dp[i][j] = dp[i - 1][j];
        forn(j, 10){
            double aux = max(dp[i - 1][j].fr, 0.0) + log10(v[i]); //Pruebo agregar ese valor
            if(aux > dp[i][((dp[i - 1][j].fr == -1 ? 1 : j) * v[i]) % 10].fr)
                if(dp[i - 1][j].fr == -1 ) dp[i][(1 * v[i]) % 10] = {aux, {{-1, -1}, i}};
                else dp[i][(j * v[i]) % 10] = {aux, {{i - 1, j}, i}};
        }
    }

    
    if(dp[n - 1][d].fr > -0.5){
        vector<int> rta{v[dp[n - 1][d].sc.sc]};
        pair<int, int> pos = dp[n - 1][d].sc.fr;

        while(pos.fr != -1){
            rta.pb(v[dp[pos.fr][pos.sc].sc.sc]);
            pos = dp[pos.fr][pos.sc].sc.fr;
        }

        cout << rta.size() << '\n';
        for(int &i : rta) cout << i << ' ';
    }
    else cout << -1;
    cout << '\n';

    return 0;
}