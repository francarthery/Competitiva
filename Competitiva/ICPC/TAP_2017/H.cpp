#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int n, rta = 0;
    bool sub = true, igual = true;
    cin >> n;

    vector<int> v(n);
    forn(i, n){
        cin >> v[i];
    } 

    forn(i, n-1){
        if(v[i] != v[i+1]){
            igual = false;
            break;
        }
    }

    if(!igual){
        if(v[0] > v[1]){
            sub = false;
            rta++;
        }

        forr(i, 2, n){
            if(sub and v[i - 1] > v[i]){
                rta++;
                sub = false;
            }
            else if(!sub and v[i - 1] < v[i]){
                sub = true;
            }
            //dbg(rta);
            //dbg(i);
        }

        if(sub) rta++;
    }
    else{
        if(v[0] != 0) rta = 1;
    }


    cout << rta << '\n';

    return 0;
}