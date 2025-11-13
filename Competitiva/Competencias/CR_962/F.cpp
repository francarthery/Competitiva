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

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ii> v(n);
        for(auto &[a, b] : v) cin >> a;
        for(auto &[a, b] : v) cin >> b;
        int ma = 0;
        forn(i, n) ma = max(ma, v[i].fr);

        ll l = -1, r = ma + 1, m, temp;
        while(r - l > 1) { //Binaria sobre el valor al que tienen que ser menor o igual todos los elemenos
            m = (l + r) / 2;
            temp = 0;
            
            forn(i, n){
                if(v[i].fr > m){
                    double cant = (v[i].fr - m) / (double)v[i].sc;
                    temp += cant + (cant == floor(cant) ? 0 : 1);
                }
            }
            
            if(temp <= k) r = m; 
            else l = m;
        }
        //dbg(r);

        ll rta = 0;
        forn(i, n){
            if(v[i].fr > r){
                double cant = (v[i].fr - r) / (double)v[i].sc;
                temp = cant + (cant == floor(cant) ? 0 : 1); //La cantidad de veces que resto
                rta += temp * v[i].fr - ((temp * (temp - 1)) / 2) * v[i].sc; //Cuanto sumo restando temp veces
                v[i].fr -= v[i].sc * temp;
                k -= temp;
            }    
        }
        //dbg(rta);

        if(k > 0){ //Puede que me sobren como maximo n - 1
            priority_queue<ii> pq(all(v));
            while(k > 0 and pq.top().fr > 0){
                rta += pq.top().fr;
                ii aux = pq.top();
                aux.fr -= aux.sc;
                pq.pop();
                pq.push(aux);
                k--;
            }
        }

        cout << rta << '\n';
    }
    
    return 0;
}