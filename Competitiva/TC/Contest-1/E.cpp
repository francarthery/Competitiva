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

    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans=0, subtot=0, tot=0, num;

    if(n == 1){
        cin >> num;
        cout << num;
    }else{
        forn(i, n){
            cin >> v[i];
            tot+= v[i];
        }
        ans = tot;
        sort(v.rbegin(), v.rend());
        while(v.size() > 2){
            subtot+= v.back();
            ans+= v.back();
            ans+= tot - subtot;
            v.pop_back();
        }
        ans+= v.back();
        v.pop_back();
        ans+= v.back();
        cout << ans;
    }

    
    return 0;
}