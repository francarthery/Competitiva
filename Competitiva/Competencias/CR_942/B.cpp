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
    string pal;
    cin >> t;

    while(t--){
        cin >> n >> pal;
        int cont = 0;
        for(char c : pal){
            if(c == 'U') cont++;
        }

        if(cont % 2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}