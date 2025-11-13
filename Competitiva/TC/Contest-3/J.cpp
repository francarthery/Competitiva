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

    ll n, k, cant = 0, sum = 0, rta;
    char ant = '#';
    string s;
    cin >> n >> k   ;
    prq<ll, vector<ll>, greater<ll>> pq;
    vector<ll> v(n);
    forn(i, n) cin >> v[i];
    cin >> s;

    forn(i, n){
        if(s[i] == ant){
            if(cant == k and v[i] > pq.top()){
                pq.pop();
                pq.push(v[i]);
            }else if(cant < k){
                cant++;
                pq.push(v[i]);
            }
        }else{
            while(!pq.empty()){
                sum+= pq.top();
                pq.pop();
            }
            cant = 1;
            ant = s[i];
            pq.push(v[i]);
        }
    }
    while(!pq.empty()){
        sum+= pq.top();
        pq.pop();
    }

    cout << sum << '\n';
    
    return 0;
}