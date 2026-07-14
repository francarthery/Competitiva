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

    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    forn(i,n) cin>>a[i];
    forn(i,m) cin>>b[i];
    int j=0, sob=0;
    forn(i,n){
        if(j >= m) break;
        if(b[j] < a[i]){
            sob += b[j];
            j++;
        }
        b[j] -= a[i];
    }

    while(j<m){
        sob += b[j];
        j++;
    }

    cout<<sob<<endl;

    return 0;
}