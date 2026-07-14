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

    ll n,m;
    cin>>n>>m;
    ll rta = 2;
    forn(i,2){
        forr(j,2,n+1){
            rta += 1ll<<(n-j);
        }
    }
    forn(i,2){
        forr(j,2,m+1){
            rta += 1ll<<(m-j);
        }
    }

    cout<<rta<<endl;

    return 0;
}