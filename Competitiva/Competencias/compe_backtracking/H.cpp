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
ll rta = 0;
string prueba;
map<ll, ll> m, c; //cuantos de cada dig hay
vector<ll> fact{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};
unordered_set<string> s;

void f(int rest, int ind){
    if(!rest){
        if(s.find(prueba) == s.end()){ //Verifico que la permutacion sea unica
            ll cif_rep = 1ll, cifras = 0; //Como minimo hay una cifra de cada numero
            for(auto i : c){
                cif_rep *= fact[i.sc];
                cifras += i.sc;
            }
            rta += (fact[cifras] - c[0] * fact[cifras - 1]) / cif_rep;
            s.insert(prueba);
        }
        return;
    }

    if(m.find(ind) != m.end() and m[ind] != 0){
        m[ind]--;
        rest--;
        f(rest, ind);
        c[ind]++;
        prueba.pb(ind + '0'); //Verifico que permutacion tengo
        f(rest, ind);
        c[ind]--;
        prueba.pop_back();
        rest++;
        m[ind]++;
    }
    else f(rest, ++ind);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string num;
    cin >> num;
    for(char c : num) m[c - '0']++;
    for(auto &i : m) if(i.sc > 0){
        i.sc--; //Si o si tengo que usar 1 de cada numero que tengo
        c[i.fr]++;
        prueba.pb(i.fr + '0');
    }

    f(num.size() - m.size(), 0);
    
    cout << rta << '\n';
    
    return 0;
}