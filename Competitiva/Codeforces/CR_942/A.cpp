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

    int n, t, x;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> b(n), a(n);
        int rta = 0;

        forn(i, n)
            cin >> a[i];
  
        forn(i, n)
            cin >> b[i];

        forn(i, n){
            if(a[i] > b[i]) {
                a.pb(b[i]);
                sort(a.begin(), a.end());
                a.pop_back();
                rta++;
            }
        }
        cout << rta << '\n';
    }
    return 0;
}