#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ws <<" "<<
#define vdbg(x){cout<<#x<<" = "<<x; for(auto e : x) cout<<x<<' ';cout<<endl;}
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

    int n; cin >> n;
    vector<int> a(n), b(n);
    set<int> sa, sb;
    forn(i, n) {
        cin >> a[i];
        sa.insert(a[i]);
    }
    forn(i, n) {
        cin >> b[i];
        sb.insert(b[i]);
    }

    bool ultk = false;
    int ind1 = -1;
    forn(i, n) if(b[i] == 1) ind1 = i;
    if(ind1 != -1){
        ultk = true;
        forr(i, ind1, n) if(b[i] != i - ind1 + 1) ultk = false;
    }

    ll ans = 0;
    // dbg(ultk);
    if(ultk) {
        bool ok = true;
        int k = b.back();
        forn(i, n) {
            if(b[i] == 1) break;
            if(b[i] != 0 and b[i] < k + i + 2) ok = false;
        }
        if(k == n) ans = 0;
        else if(sa.count(k+1) and ok) ans = n - k;
        else ans = 2*n - k + 1;
    }
    else {
        if(sb.count(1)) {
            int ind = -1, ma = 0;
            forn(i, n) {
                if(b[i] == 1) {
                    ind = i;
                    break;
                }     
            }   
            forr(j, ind+1, n) if(b[j] != 0) ma = max(ma, (j - ind + 1) - b[j]);
            //dbg(ind); dbg(ma); 
            ans = n + (ind + 1) + ma;
        }
        else {
            int ma = 0;
            forn(i, n) if(b[i] != 0) ma = max(ma, i+2-b[i]);
            ans = n + ma;
        }
    }

    cout << ans << '\n';

    return 0;
}