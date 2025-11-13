#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
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
    
    int t, n, k, num, rta;
    cin >> t;
    while(t--){
        cin >> n >> k;
        num = 1; rta = 0;

        if(n == 1){
            cout << k << '\n';
            continue;
        } 

        while(rta + num <= k){
            rta += num;
            num *= 2;
        }

        cout << rta << ' ' << k - rta;
        forn(i, n - 2) cout << " 0";
        cout << '\n';
    }

    return 0;
}