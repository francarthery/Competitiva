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
    
    long long n, x, rta = 1, cont = 0;
    cin >> n;
    vector<int> v(n);
    priority_queue<int> pq;

    forn(i, n) cin >> v[i];
    forn(i, n){
        cin >> x;
        pq.push(x);
    }
    sort(v.rbegin(), v.rend());

    forn(i, n){
        while(!pq.empty() and pq.top() >= v[i]){
            cont++;
            pq.pop();
        }
        rta *= cont;
        rta %= (int)(1e9 + 7);
        cont--;
    }

    cout << rta << '\n';

    return 0;
}