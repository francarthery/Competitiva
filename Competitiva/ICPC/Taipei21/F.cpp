#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int) (x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto e : x) cout<<e<<" ";cout<<endl;}
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


bool in(int a, int x, int c){
    return a<=x && x<=c;
}

void comp(vector<int> &v){
    // vdbg(v);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    // vdbg(v);
}

typedef tuple<short,short,short> iii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("in1","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n;cin>>n;
    vector<array<int,2>>x(n), y(n);
    vector<int> X, Y;
    vector<short> c(n);
    forn(i,n){
        forn(j,2){
            cin>>x[i][j]>>y[i][j];
            X.push_back(x[i][j]);
            Y.push_back(y[i][j]);
        }
        cin>>c[i];
    }
    comp(X);
    comp(Y);
    forn(i,n){
        forn(j,2){
            x[i][j] = lower_bound(all(X), x[i][j]) - X.begin();
            y[i][j] = lower_bound(all(Y), y[i][j]) - Y.begin();
        }
    }

    unordered_map<unsigned int, vector<iii>> rng;

    short x1,y1,y2;
    forn(i,n){
        x1 = x[i][0];
        y1 = y[i][1];
        y2 = y[i][0];
        forr(j,y1,y2+1){
            rng[(x1<<16)|j].push_back({i, x[i][1], c[i]});
        }
    }

    set<short> col;
    forn(y,sz(Y)){
        priority_queue<iii> pq;
        forn(x,sz(X)){
            while(pq.size() && get<1>(pq.top()) <= x){
                pq.pop();
            }
            for(auto &tup : rng[(x<<16)|y]){
                pq.push(tup);
            }
            rng.erase((x<<16)|y);
            if(pq.size())
                col.insert(get<2>(pq.top()));
        }
    }

    cout<<sz(col)<<"\n";
}