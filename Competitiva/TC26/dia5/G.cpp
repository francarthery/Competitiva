    #include <bits/stdc++.h>
    #define forr(i,a,b) for(int i=a;i<b;i++)
    #define forn(i,n) forr(i,0,n)
    #define dfor(i,n) for(int i=n-1; i>=0;i--)
    #define sz(x) (int(x.size()))
    #define all(x) x.begin(), x.end()
    #define rall(x) x.rbegin(), x.rend()
    #define dbg(x) cout<<#x<<" = "<<x<<endl;
    #define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
    #define nl cout<<"\n";
    #define ws <<" "<<

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

        int a[6];
        forn(i,6)cin>>a[i];

        int lvl = 0;
        ll cnt = a[0];
        ll rta = 0;
        while(lvl < a[1] && lvl < a[5]){
            rta += cnt;
            rta += cnt+1;
            cnt++;
            lvl++;
        }
        while((lvl < a[1] + a[2]) && (lvl < a[1] || lvl < a[5])){
            rta += cnt * 2;
            lvl++;
        }
        while(lvl < a[1]+a[2]){
            rta += cnt;
            rta += cnt-1;
            cnt--;
            lvl++;
        }

        cout<<rta<<endl;

        return 0;
    }