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
    vector<ll> v(n);
    forn(i, n) cin >> v[i];

    bool pa = true, uno = false;
    ll tot = 0, par = 0, impar = 0, par2 = 0, impar2 = 0, tempp = 0;
    forn(i, n){
        if(v[i] == 0 and !uno) tempp++;
        else if(v[i] == 1 and pa){
            par += impar2 + 1, pa = !pa;
            par2++;
            par += tempp;
            tempp = 0;
            uno = true;
        }
        else if(v[i] == 1 and !pa) {
            impar += par2, pa = !pa;
            impar2++;
        }
        else {
            if(!pa) par += par2;
            else impar += impar2; 
        }
        dbg(par); dbg(impar);
    }

    dbg(par); dbg(impar);
    cout << par + impar << '\n';




    return 0;
}