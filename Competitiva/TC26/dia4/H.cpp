#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<< " = " <<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r", stdin);
    freopen("out","w",stdout);
    #endif
    
    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];

    if(n < 4) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    
    if(n == 5) {
        cout << "3 + 4 = 7\n";
        cout << "7 + 5 = 12\n";
        cout << "2 * 12 = 24\n";
        cout << "1 * 24 = 24\n";
        return 0;
    }

    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
    if(n == 4) cout << "1 * 24 = 24\n";
    else {
        cout << "6 - 5 = 1\n";
        cout << "1 - 1 = 0\n";
        forr(i, 7, n+1) {
            cout << "0 * " << i << " = 0\n";
        }

        cout << "24 + 0 = 24\n";
    }

    return 0;
}