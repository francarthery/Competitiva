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
    
    vector<string> v{"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL",
"SOL#", "LA", "LA#", "SI"};

    int n, ind;
    string cad;

    cin >> n >> cad;
    forn(i, 12){
        if(v[i] == cad) ind = i;
    }

    cout << v[(ind + 12 - n) % 12] << '\n';
    
    

    return 0;
}