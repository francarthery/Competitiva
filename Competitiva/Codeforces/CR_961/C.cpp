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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n;
    cin >> t;

    while(t--){
        cin >> n;
        ll cont = 0, x, ma = 0, movant = 0, aux;
        bool flag = true;
        vector<ll> v(n);
        forn(i, n){
            cin >> x;
            v[i] = x;
            if(x == 1 and ma > 1) flag = false;
            ma = max(ma, x);
        }
        
        if(flag){
            forr(i, 1, n){
                if(v[i] > v[i - 1] and !movant) continue;
                if(v[i] <= v[i - 1]){
                    aux = v[i];
                    while(aux < v[i - 1]){
                        aux *= aux;
                        movant++;
                    }
                }
                else{
                    aux = v[i - 1];
                    while(aux < v[i]){
                        aux *= aux;
                        movant--;
                    }
                    if(aux > v[i]) movant++;
                }
                movant = max(movant, 0ll);
                cont += movant;
            }
        }

        cout << (flag ? cont : -1) << '\n';
    }
    
    return 0;
}