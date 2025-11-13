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

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s; cin >> s;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        int l = -1, r = *max_element(all(v)) + 1;
        while(r - l > 1){
            int m = (l + r) / 2;

            int cont = 0, ini = -1;
            forn(i, n){
                if(s[i] == 'B' and v[i] > m and ini == -1) { //Abro rango
                    cont++;
                    ini = i;
                }
                else if(s[i] == 'R' and v[i] > m and ini != -1){ //Cierro rango
                    ini = -1;
                }
            }

            if(cont > k) l = m;
            else r = m;
        }

        cout << r << '\n';
    }



    return 0;
}