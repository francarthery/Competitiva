#include <bits/stdc++.h>
#define int long long
//perdon
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) cout<<#x<<": [";for(auto e:x)cout<<e<<", ";cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";


using namespace std;

typedef pair<int,int> ii;
typedef  long long ll;

typedef ll td;
typedef vector<ll> vi;
typedef vector<td> vd;
const ll INF = 3e18;
bool zz(td x){return abs(x) == 0;}
struct Hungarian{
    int n;
    vi L,R;
    vector<vd>cs;
    Hungarian(int N, int M) : n(max(N,M)), cs(n,vd(n)), L(n), R(n){
        forn(x,N) forn(y,M) cs[x][y]=INF;
    }
    void set(int x, int y, td c){cs[x][y]=c;}
    td assign(){
        int mat = 0;
        vd ds(n), u(n), v(n);
        vi dad(n), sn(n);
        forn(i,n) u[i]=*min_element(all(cs[i]));
        forn(j,n){
            v[j]=cs[0][j]-u[0];
            forr(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);
        }
        L=R=vi(n,-1);
        forn(i,n)forn(j,n)if(R[j]==-1&&zz(cs[i][j]-u[i]-v[j])){
            L[i]=j,R[j]=i,mat++;
            break;
        }
        for(;mat<n;mat++){
            int s=0,j=0,i;
            while(L[s]!=-1)s++;
            fill(all(dad),-1);
            fill(all(sn),0);
            forn(k,n)ds[k]=cs[s][k]-u[s]-v[k];
            while(1){
                j=-1;
                forn(k,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
                sn[j]=1,i=R[j];
                if(i==-1)break;
                forn(k,n)if(!sn[k]){
                    td new_ds=ds[j]+cs[i][k]-u[i]-v[k];
                    if(ds[k]>new_ds)ds[k]=new_ds,dad[k]=j;
                }
            }
            forn(k,n)if(k!=j&&sn[k]){
                td w=ds[k]-ds[j];
                v[k]+=w,u[R[k]]-=w;
            }
            u[s]+=ds[j];
            while(dad[j]>=0){
                int d = dad[j];
                R[j]=R[d],L[R[j]]=j,j=d;
            }
            R[j]=s,L[s]=j;
        }
        td ret = 0;
        forn(i,n)ret +=cs[i][L[i]];
        return ret;
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
 
    int n;cin>>n;
    vector<vector<ll>>v(n+3,vector<ll>(n+4));
    forn(i,n)forn(j,n){
        cin>>v[i+1][j+1];
    }
    Hungarian h((n+n%2)/2,(n+1)/2);
 
    for(int i=2;i<=n+(n%2);i+=2){
        for(int j=1;j<=n;j+=2){
            h.set((i-1)/2,(j-1)/2,v[i-2][j]+v[j][i]);
        }
    }
 
    cout<<h.assign();nl;
 
 
    return 0;
}