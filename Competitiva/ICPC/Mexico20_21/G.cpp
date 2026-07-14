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

    ll l, g; cin >> l >> g;
    ll izq = 0, der = 1e17;

    forn(i, g){
        ll dir, pos; cin >> pos >> dir;
        if(dir) der = min(der, pos);
        else izq = max(izq, pos);
    }

    cout << max(l - der, izq) << '\n';
    return 0;
}