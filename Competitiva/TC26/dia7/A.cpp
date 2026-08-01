    #include <bits/stdc++.h>
    #define forr(i,a,b) for(int i=a;i<b;i++)
    #define forn(i,n) forr(i,0,n)
    #define dfor(i,n) for(int i=n-1; i>=0; i--)
    #define sz(x) (int(x.size()))
    #define all(x) x.begin(), x.end()
    #define rall(x) x.rbegin(), x.rend()
    #define dbg(x) cout<<#x <<" = "<<x<<endl;
    #define vdbg(x) cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;
    #define ws <<" "<<
    #define nl cout<<"\n";
    using namespace std;

    typedef long long ll;
    typedef pair<int,int> ii;
    typedef long double ld;

    int main(){

        cin.tie(0);
        ios_base::sync_with_stdio(0);

        #ifdef fran
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
        #endif

        int n, h; cin >> n >> h;
        // dbg(deseo);
        vector<ld> ans(n-1);
        
        forn(i, n-1) {
            ld deseo = ((ld)h *(i+1) / (2*n));
            // dbg(deseo);
            ans[i] = sqrtl(deseo * 2*h);        
        }

        forn(i, n-1)
            cout << fixed << setprecision(15) << ans[i] << ' ';
        cout << '\n';
        return 0;
    }

    // htot = 0.367007
    // htot = 1.81002
    // 0.367006838105 1.810023280995 
