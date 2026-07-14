
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

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<bool> del(n);

        int abre = 0, cierra = 0, best = 1e9;
        for(char c : s) {
            if(c == '(') abre++;
            else cierra++;
        }

        forn(x, k+1) {
            int abre2 = 0, cierra2 = 0, neto = 0, profit = 0;
            vector<bool> elim(n);
            forn(i, n) {
                if(s[i] == '(') {
                    if(abre2 < x) {
                        abre2++;
                        elim[i] = true;
                    }
                    else neto++;
                }
                else {
                    cierra2++;
                    if(cierra - cierra2 >= k - x) {
                        if(neto > 0) profit += 2;
                        neto--;
                        neto = max(0, neto);
                    }
                    else elim[i] = true;
                }
            }

            if(profit < best) {
                best = profit;
                del = elim;
            }
        }
    
        for(auto i : del) cout << i;
        cout << '\n';
    }



    return 0;
}