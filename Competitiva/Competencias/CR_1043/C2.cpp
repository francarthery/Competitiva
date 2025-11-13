#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll cost = 0;
        vector<int> bases(30);
        while(n){
            int val = log10(n) / log10(3); 
            ll num = pow(3, val);
            n -= num;
            bases[val]++;
            k--;
        }

        if(k < 0){
            cout << -1 << '\n';
            continue;
        }

        k -= k % 2;
        int ind = 29;
        while(k){
            while(!bases[ind]) ind--;
            if(ind == 0) break;

            ll oper = min(k, bases[ind] * 2ll);
            bases[ind] -= oper / 2;
            k -= oper;

            bases[ind - 1] += (oper * 3) / 2;
        }

        forn(i, 30){
            ll num = pow(3, i);
            cost += bases[i] * (num * 3 + i * (num / 3));
        }
        
        cout << cost << '\n';
    }



    return 0;
}