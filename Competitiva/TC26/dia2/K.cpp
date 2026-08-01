#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ws <<" "<<
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    ll n; cin >> n;
    string s; cin >> s;
    ll cont = 0, tot = 0;
    forn(i, n-10){
        tot++;
        if(s[i] == '8') cont++;
    }

    cout << (cont * 2 > tot ? "YES" : "NO") << '\n';


    return 0;
}