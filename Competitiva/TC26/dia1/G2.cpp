#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct lis{
    int n;
    int INF;
    vector<pair<int, int>> d;
    vector<int> ret;
    vector<int> a;


    lis(int i, vector<int> &v){
        INF = i;
        n = sz(v);
        d.resize(n+1);
        a = v;
    }

    int run(){
        d[0] = {INF,-1};
        forn(i,n) d[i+1] = {INF,-1};
        forn(i,n){
            int j = int(upper_bound(all(d), make_pair(a[i], n)) - d.begin());
            if(d[j-1].first < a[i] && a[i] < d[j].first){
                d[j] = {a[i],i};
            }
        }
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> p(n+1);
    forn(i,n){
        int x;cin>>x;
        p[x]=i+1;
    }

    vdbg(p);

    while(p[n] == n-1) n--;
    int mx = p[n], cnt=(n > 0);
    for(int i=n-1; i>=1 && n; i--){
        if(p[i] > mx){
            mx = p[i];
            cnt++;
        }
    }

    cout << n-cnt << '\n';
    
    return 0;
}