#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

long long a, b, t, n, m, temp, contador;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    
    cin >> t;

    while(t--){
        cin >> n >> m;
        contador = n;
        for(long long b = 2; b<=m; b++){
            long long k=b*b;
            for(long long a = b; a<=n; a+=b){
                if((a+b)%k == 0) contador++;
            }
            
        }
        cout << contador << '\n';
    }


    return 0;
}