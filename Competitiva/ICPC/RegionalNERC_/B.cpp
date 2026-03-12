#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(stru) (int(stru.size()))
#define all(stru) stru.begin(), stru.end()
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

typedef ll T;
const T EPS = 0;
const T INF = 1e18;
struct pto{
    T x,y;
    pto() : x(0), y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator- (pto b) {return  pto(x-b.x, y-b.y);}
    T operator^(pto b) {return x*b.y - y*b.x;}
    T side (pto a, pto b) {return ((a-*this) ^ (b-*this));}
    bool left(pto a, pto b) {return ((a-*this) ^ (b-*this)) > 0;}
    bool right(pto a, pto b) {return ((a-*this) ^ (b-*this)) < 0;}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pto> v(n);
        forn(i,n){
            int x,y; cin>>x>>y;
            v[i]=pto(x,y);
        }

        int i=0,j=1,k=2, ans=0;
        forn(st,n-2){
            i=max(i,st);
            j=max(j,st+1);
            k=max(k,st+2);
            while(k<n && v[k].right(v[i],v[j]) && v[st].right(v[j],v[k]) && v[st+1].right(v[k],v[st])){
                i++,j++,k++;
                ans=max(ans,k-st);
            }
        }

        cout<<ans<<endl;
    }


    return 0;
}