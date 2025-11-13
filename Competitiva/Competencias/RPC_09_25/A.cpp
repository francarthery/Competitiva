#include<bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) for(int i=0; i<n; i++)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(a) ((int)(a.size()))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) <<endl;
#define vdbg(x) {cout <<"["; for(auto i:x){cout << i << ", "; cout << "]" <<endl; }}
#define ws <<' '<<
#define nl cout<<endl;
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
const int N = 20006;
const int inf = 1e9;
int NEUT = -inf;

#define oper(a,b) max(a,b)
const int MAXN = 4048;
int a[MAXN][MAXN], st[2*MAXN][2*MAXN];
int n,m;
void build(){
    forn(i,n) forn(j,m) st[i+n][j+m] = a[i][j];
    forn(i,n) dfor(j,m)    
        st[i+n][j] = oper(st[i+n][j<<1], st[i+n][j<<1 | 1]);
    dfor(i,n) forn(j, 2*m){
        st[i][j] = oper(st[i<<1][j], st[i<<1 | 1][j]);
    }
}

int query(int x0, int x1, int y0, int y1){
    int r = NEUT;
    for(int i0 = x0 + n, i1 = x1 + n; i0 < i1; i0>>=1, i1>>=1){
        int t[4], q = 0;
        if(i0 & 1) t[q++] = i0++;
        if(i1 & 1) t[q++] = --i1;
        forn(k, q){
            for(int j0 = y0 + m, j1 = y1 + m; j0 < j1; j0>>=1, j1>>=1){
                if(j0 & 1) r = oper(r, st[t[k]][j0++]);
                if(j1 & 1) r = oper(r, st[t[k]][--j1]);
            }
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    

    vector<vector<ii>> coord(N);
    vector<int> freq(N);
    cin >> n >> m;

    int mn = inf;
    forr(i,0,n){
        forr(j,0,m){
            cin >> a[i][j];
        }
    }
    build();

    int r, c; cin >> r >> c;

    forr(i,0,n-r+1){
        cout <<  query(i, i+r, 0, c);
        forr(j,1,m-c+1){
            cout << ' ' << query(i, i+r, j, j+c);
        }
        nl;
    }

    return 0;

}