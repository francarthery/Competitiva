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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
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

    ll d, d1, m, n, d2, rta = 0;
    cin >> d >> m >> d1 >> n >> d2;
    
    if(m > 65) m = 65;
    if(n > 65) n = 65;
    
    if(d1 > d){
        while(m > 0 and d > 0){
            d -= (d1 - d);
            m--;
            rta++;
        }
    }
    if(d > 0 and d2 > d){
        while(n > 0 and d > 0){
            d -= d2 - d;
            n--;
            rta++;
        }
    }

    if(d <= 0) cout << rta << '\n';
    else cout << "-1\n";

    return 0;
}