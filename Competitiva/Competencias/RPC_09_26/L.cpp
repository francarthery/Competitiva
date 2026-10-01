#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

void r(int testc){
    int h,w;
    cin>>h>>w;
    string s[h];
    forn(i,h)
        cin>>s[i];

    auto ok = [&] (int i, int n) -> bool {
        return i>=0 && i < n;
    };

    vector<ii> movs = {{-1,0},{0,-1},{0,1},{1,0}};
    int fi, fj;
    vector<vector<ii>> fat;
    
    auto bfs = [&](int ssi, int ssj) -> tuple<int,int,int> {
        const int inf = 1e9;
        vector<vector<int>> dst(h, vector<int>(w,inf));
        dst[ssi][ssj]=0;
        queue<ii> q;
        q.push({ssi,ssj});
        fat = vector<vector<ii>>(h,vector<ii>(w));

        int mx = 0;
        int ri, rj;

        while(q.size()){
            auto [i,j] = q.front();
            q.pop();
            for(auto [di,dj] : movs){
                int ni = i+di;
                int nj = j+dj;

                if(!ok(ni,h)) 
                    continue;
                if(!ok(nj,w)) 
                    continue;
                if(s[ni][nj] != '.')
                    continue;
                if(dst[ni][nj] != inf)
                    continue;

                q.push({ni,nj});
                dst[ni][nj] = dst[i][j]+1;
                if(dst[ni][nj] > mx){
                    ri=ni;
                    rj=nj;
                    mx = dst[ni][nj];
                }
                fat[ni][nj] = {i,j};
            }
        }
        return {mx,ri,rj};
    };

    forn(i,h){
        int f = 0;
        forn(j,w){
            if(s[i][j]=='.'){
                auto [a,b,c] = bfs(i,j);
                fi = b;
                fj = c;
                f=1;
                break;
            }
        }
        if(f)break;
    }
    dbg(fi);
    dbg(fj);

    auto [d, si, sj] = bfs(fi,fj);

    dbg(d);
    dbg(si);
    dbg(sj);
    set<ii> rta;
    int auxd=d;
    while(auxd >= d/2){
        if(auxd == d/2 || auxd == (d+1)/2){
            dbg(auxd);
            rta.insert({sj,si});
        }
        cout<<si<<" "<<sj<<endl;
        si = fat[si][sj].first;
        sj = fat[si][sj].second;
        auxd--;
    }

    auto [j,i] = *rta.begin();
    cout<<"Case "<<testc<<": "<<i+1<<" "<<j+1<<"\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef chichu
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int t;
    cin>>t;
    forn(i,t)
        r(i+1);

    return 0;
}