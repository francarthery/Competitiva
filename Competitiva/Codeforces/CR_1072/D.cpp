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

    vector<map<int, int>> v(32);
    v[1][1] += 1;
    v[2][1] += 1;
    v[2][2] += 1;
    v[2][3] += 1;

    v[3] = v[2];
    v[3][3] += 1;
    v[3][4] += 2;
    v[3][5] += 1;

    map<int, int> ant;
    ant[3] = 1;
    ant[4] = 2;
    ant[5] = 1;

    forr(i, 4, 32){
        map<int, int> nant;
        for(auto j : ant) {
            v[i][j.fr + 1] += j.sc;
            v[i][j.fr + 2] += j.sc;

            nant[j.fr + 1] += j.sc;
            nant[j.fr + 2] += j.sc;
        }

        for(auto j : v[i - 1]){
            v[i][j.fr] += j.sc;
        }
        ant = nant;
    }

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ind = __lg(n);

        int rta = k >= ind + 1 ? 0 : 1;
        for(auto j : v[ind]) {
            if(j.fr > k) rta += j.sc;
        }

        cout << rta << '\n';
    }


    // int t; cin >> t;
    // while(t--){
    //     int n; cin >> n;
    //     map<int, int> frec;
    //     forn(i, n){
    //         int cont = 0, aux = i;
    //         while(aux){
    //             if(aux&1)aux--;
    //             else aux /= 2;
    //             cont++;
    //         }
    //         frec[cont]++;
    //         cout << cont << ' ';
    //         cout << i << '\n';
    //     }
    //     int acum = 0;    
    //     for(auto i : frec) {
    //         acum += i.sc;
    //         cout << i.fr << ' ' << i.sc << ' ' << acum << '\n';
    //     }
    // }

    return 0;
}