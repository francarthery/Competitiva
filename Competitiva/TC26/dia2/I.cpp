#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
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

    int n;cin>>n;
    string s;cin>>s;
    map<char,char>f;
    forr(i,1,10) cin>>f[i+'0'];
    int j=0;
    string rta = s;
    forn(i,n){
        int ff=0;
        if(f[s[i]] > s[i]){
            int j = i;
            while(j < n && f[s[j]] >= rta[j]){
                rta[j] = f[s[j]];
                j++;
            }
            ff=1;
        }
        if(ff) break;
    }
    rta = max(rta,s);
    cout<<rta<<endl;
    return 0;
}