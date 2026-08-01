#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif

    int n;cin>>n;
    set<int> v;
    vector<int> t(n+1);
    int mx = 0;
    int tini=0;
    forn(i,n){
        char c;
        int x;
        cin>>c>>x;
        if(c == '+'){
            t[i] = 1;
            v.insert(x);
        } else {
            if(v.count(x)){
                v.erase(x);
                t[i] = -1;
            } else {
                t[i] = -1;
                tini++;
            }
        }
    }
    t[0] += tini;
    // vdbg(t);
    forr(i,1,n){
        t[i] += t[i-1];
    }
    // vdbg(t);
    int rta = tini;
    rta = max(rta, *max_element(all(t)));

    cout<<rta<<endl;

    return 0;
}