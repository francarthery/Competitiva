#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, costo, car, mi = INT_MAX;
    cin >> n;
    vector<int> v;

    forr(i, 1, 10){
        cin >> costo;
        
        if(costo <= n and costo <= mi){
            mi = costo;
            car = i;
        }
        
        v.pb(costo);
    }

    string ans;

    if(mi == INT_MAX) ans = "-1";
    else{
        int cant = n/mi;
        
        forn(i, cant) ans += car + '0';

        int sobra = n%mi;

        bool flag = false;
        int cambio = 0;
        if(sobra != 0) flag = true;
        int pos = 0;

        while(flag){
            sobra+= mi;
            for(int i = 8; i >= 0; i--){
                if(v[i] <= sobra and ans[pos] - '0' < (i + 1)){
                    ans[pos] = i + 1 + '0';
                    sobra-= v[i];
                    if(!sobra) flag = false;
                    break;
                }else if(i == 1) flag = false;
            }
            pos++;
        }
    }
    cout << ans;
    
    return 0;
}