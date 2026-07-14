#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()


using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w",stdout);
    #endif

    int n; cin >> n;
    const int MAXN = 1e7+1;
    vector<int> criba(MAXN);
    criba[1] = 1; 
    forr(i, 2, MAXN) if(!criba[i]) for(int j = i; j < MAXN; j += i) criba[j] = i;

    forn(i, n){
        ll x, y; cin >> x >> y;

        unordered_set<ll> s;
        while(x != criba[x]) {
            s.insert(criba[x]);
            // cout << x << '\n';
            x /= criba[x];
        }
        if(x != 1) s.insert(x);
        
        while(y != criba[y]) {
            s.insert(criba[y]);
            y /= criba[y];
        }
        if(y != 1) s.insert(y);

        cout << sz(s) << '\n';
    }
    return 0;
}