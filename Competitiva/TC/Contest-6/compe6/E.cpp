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

    int n, x, num = -1;
    cin >> n;
    vector<int> v(n);
    forn(i, n){
        cin >> x;
        if(!(x & (x - 1)) and x) num = x;
        v[i] = x;
    }
    sort(all(v));
    vector<int> rta, temp;
    bool flag = false, pepe = true;

    forn(i, n){
        int pot = 1;
        auto it = v.begin();
        pepe = true;
        
        while(!flag and pot < 1e9){
            if(!pepe) pot *= 2;
            pepe = false;

            temp.clear();
            temp.pb(v[i]);
            it = lower_bound(all(v), v[i] + pot);
            if(it == v.end() or *it != v[i] + pot) continue;
            temp.pb(*it);

            if(temp.size() > rta.size()) rta = temp;

            it = lower_bound(all(v), v[i] + pot * 2);
            if(it == v.end() or *it != v[i] + pot * 2) continue;
            temp.pb(*it);

            if(temp.size() > rta.size()) rta = temp;
            if(rta.size() == 3) flag = true; //OJO
        }

        if(flag) break;    
    }

    if(rta.size() <= 1){
        cout << 1 << '\n' << v[0] << '\n';
    }
    else{ 
        cout << rta.size() << '\n';
        forn(i, sz(rta)) cout << rta[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}