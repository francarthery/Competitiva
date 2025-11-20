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
typedef pair<ll, ll> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t, n, mon, x, y, temp;
    cin >> t;
    while(t--){
        ll ma = 0;
        cin >> n >> mon;
        vector<ii> v(n);
        for(auto &[x, y] : v) cin >> x;
        for(auto &[x, y] : v) cin >> y;
        sort(all(v));

        forr(i, 1, n){
            if(v[i].fr - v[i - 1].fr != 1) continue;
            int x = 0, y = 0;
            temp = 0;
            x = min(mon / v[i].fr + 1, v[i].sc); //Pongo del primero hasta que no me quede o pasarme por 1
            temp += x * v[i].fr;
            if(temp < mon){
                y = min((mon - temp) / v[i - 1].fr + 1, v[i - 1].sc); //Pongo lo que falte o hasta que tenga del otro
                temp += y * v[i - 1].fr;
            }

            if(temp > mon){
                if(v[i - 1].sc - y >= temp - mon and temp - mon <= x) temp = mon;
                else temp -= (y > 0 ? v[i - 1].fr : v[i].fr);
            }

            ma = max(ma, temp);
        }

        forn(i, n) ma = max(ma, min(mon / v[i].fr, v[i].sc) * v[i].fr);
        cout << ma << '\n';
    }
    
    return 0;
}