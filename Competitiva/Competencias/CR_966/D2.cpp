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

    int t, n;
    char x;
    cin >> t;
    while(t--){
        cin >> n;
        ll rta = 0, contr = 0;
        vector<ll> v(n), ps(n + 1), posl, posr;
        vector<char> p(n);
        forn(i, n) cin >> v[i];
        forn(i, n){
            cin >> x;
            p[i] = x;
            if(x == 'L') posl.pb(i);
            else posr.pb(i);
        }
        reverse(all(posl));
        forn(i, n) ps[i + 1] = ps[i] + v[i]; //Prefix sum
        bool flag = true;
        while(flag){
            if(!posl.empty() and !posr.empty() and posl.back() < posr.back()){
                rta += ps[posr.back() + 1] - ps[posl.back()];
                posr.pop_back();
                posl.pop_back();
            }
            else flag = false;
        }

        cout << rta << '\n';
    }

    return 0;
}