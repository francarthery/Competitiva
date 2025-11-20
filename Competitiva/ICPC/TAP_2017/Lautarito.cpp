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
    
    int n, p, m=0, anterior, prim;
    bool primero = true, sub = false, baj = false;
 
    cin >> n;
 
    forn(i, n){
        cin >> p;
        if(primero){
            prim = p;
            anterior = p;
            primero = false;
        }else if(!primero and p > anterior and !sub){
            baj = false;
            sub = true;
            m++;
        }else if(!primero and p < anterior and !baj){
            baj = true;
            sub = false;
        }
        anterior = p;
    }
 
    cout << m << endl;
 
 
    return 0;
}