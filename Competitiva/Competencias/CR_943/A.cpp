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
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int max1 = 0, max2 = 0;
        for(int i = 1; i < n; i++){
            int cant = gcd(n, i) + i;
            if(cant > max1){
                max1 = max(max1, cant);
                max2 = max(max2, i);
            }
        }
        cout << max2 << '\n';
    }

    return 0;
}