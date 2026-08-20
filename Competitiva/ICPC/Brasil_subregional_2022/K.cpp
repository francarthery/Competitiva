#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif

    int t,m,d;
    cin>>t>>d>>m;
    vector<int> y(m+2);
    forn(i,m) cin>>y[i+1];
    y[m+1] = d;

    forn(i,m+1){
        if(y[i+1]-y[i] >= t) {
            cout<<"Y";nl;
            return 0;
        }
    }
    cout<<"N";nl;

    return 0;
}