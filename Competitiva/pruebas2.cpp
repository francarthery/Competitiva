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

    int n; cin >> n;
    vector<ll> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    int k, l; cin >> k >> l;
    multiset<ll> best, worst;
    vector<int> kprimeros(k);

    ll sumk = 0, ans = 0, sbest = 0, sworst = 0;
    forn(i, k) {
        kprimeros[i] = b[i];
        sumk += a[i];
    }
    sort(kprimeros.rbegin(), kprimeros.rend()); //Ordeno de mayor a menor

    forn(i, l) { //Le paso los l mejores a best
        best.insert(kprimeros[i]);
        sbest += kprimeros[i];
    } 
    forr(i, l, k) {
        worst.insert(kprimeros[i]);
        sworst += kprimeros[i];
    }

    ans = max(ans, sumk + sbest);
    forn(i, k) {
        sumk += a[n-1-i]; //Actualizo la suma de los K elementos
        sumk -= a[k-1-i];
        int entra = b[n-1-i];
        int sale = b[k-1-i];

        if(best.count(sale)) {
            best.erase(best.find(sale)); //Si esta en el primero lo saco
            sbest -= sale;
        }
        else {
            worst.erase(worst.find(sale)); //Sino esta en el segundo
            sworst -= sale;
        }

        best.insert(entra);
        sbest += entra;

        if(sz(worst)){
            best.insert(*worst.rbegin()); //El mejor de worst podria ganarle al peor de best
            sbest += *worst.rbegin(); //Por las dudas se lo paso a best y que el vea que hace
            sworst -= *worst.rbegin();
            worst.erase(*(--worst.end())); //No deja eliminar el rbegin()
        }

        while(sz(best) > l) { //best le pasa sus peores elementos a worst si tiene mas de L
            worst.insert(*best.begin()); 
            sworst += *best.begin();
            sbest -= *best.begin();
            best.erase(best.begin());
        }
        
        ans = max(ans, sumk + sbest); //me fijo si la nueva sol es mejor
    }

    cout << ans << '\n';

    return 0;
}