#include <bits/stdc++.h>
#define forr(i, a, n) for(long long i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    long long a, s, l, r, k, rta = 0, n1;
    cin >> a >> s >> l >> r;

    k = r - l + 1;

    if(a == s) cout << 1 << '\n';
    else if(a > s) cout << 0 << '\n';
    else{
        forr(d, 1, k){
            for(long long x1 = a; x1 >= l; x1 -= d){
                long long ini = 0, fin = r - l + 2, m;
                while(ini < fin){
                    m = (ini + fin) / 2;
                    if(x1 * m + (d / 2.0) * m * (m - 1) > s) fin = m;
                    else ini = m + 1;
                }
                n1 = ini - 1;
                if(n1 <= (r - x1) / (double)d + 1 and x1 + d * (n1 - 1) >= a and x1 * n1 + (d / 2.0) * n1 * (n1 - 1) == s) rta++;
            }
        }
        cout << rta << '\n';
    }

    return 0;
}