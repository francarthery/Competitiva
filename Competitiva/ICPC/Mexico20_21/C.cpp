#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()


using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef long double ld;

int n;
vector<vector<ld>> mul(vector<vector<ld>>&a, vector<vector<ld>>&b){
    vector<vector<ld>> ret(n, vector<ld> (n,0));

    forn(i,n) forn(j,n) forn(k,n){
        ret[i][j] = ret[i][j] + a[i][k] * b[k][j];
    }

    return ret;
}

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out","w",stdout);
    #endif

    int m;
    cin>>n>>m;
    vector<vector<long double>> v(n, vector<ld> (n)), ret(n, vector<ld> (n,0));
    forn(i,n) forn(j,n) cin >> v[i][j];
    forn(i,n) ret[i][i] = 1;

    while(m){
        if(m & 1){
            ret = mul(ret, v);
        }
        v = mul(v,v);
        m>>=1;
    }

    forn(i,n) cout<<fixed<<setprecision(15)<<ret[0][i]<<endl;


    return 0;
}