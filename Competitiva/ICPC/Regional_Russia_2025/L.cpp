#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) for(auto &e: x) cout<<"[";for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;



using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    ll n;cin>>n;
    ll a=0,b=0;
    if(n==0){
        cout<<"YES";nl;
        cout<<69 ws 69;nl;
        return 0;
    }
    if(__builtin_popcountll(n) == 1){
        ll i=1;
        while((n & i) == 0){
            i<<=1;
        }
        if(i>1){
            a|=i;
            b|=(i>>1);
            a|=(i>>1);
        } else {
            a|=i;
            b|=2;
            a|=2;
        }
    } else {
        int p=0;
        dfor(i,61){
            if(n & (1ll << i)){
                if(!p) {
                    b|=(1ll<<i);
                    p^=1;
                } else {
                    a|=(1ll<<i);
                }
            }
        }
    }
    if((a > 0 && a <= 1'000'000'000'000'000'000) && (b > 0 && b <= 1'000'000'000'000'000'000) && (a^b == n)){
        cout<<"YES"<<endl<< a ws b<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}