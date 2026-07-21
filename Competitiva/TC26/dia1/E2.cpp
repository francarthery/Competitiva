#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend9)()
#define dbg(x) cout<<#x <<" = " << x << endl;
#define vdbg(x) {cout<<#x<<" = ["; for(auto e : x) cout<<e<<' '; cout<<"\n";}
#define nl cout<<"\n";

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    vector<int> morfi, pac;
    forn(i, n) {
        if(s[i] == '*') morfi.push_back(i);
        else if(s[i] == 'P') pac.push_back(i);
    }
    reverse(all(morfi));
    // vdbg(morfi); vdbg(pac);

    int l = -1, r = 2*n+1;
    while(r-l>1) {
        int m = (r+l)/2;
        vector<int> eat = morfi;

        forn(i, sz(pac)) {
            int pos = pac[i];
            int mov = m;
            int dist = abs(pos - eat.back());
            if(sz(eat) and dist > mov) break;

            
        }

        if(sz(eat)) l = m;
        else r = m;
    }

    cout << r << '\n';

    
    return 0;
}