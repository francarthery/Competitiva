#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(stru) (int(stru.size()))
#define all(stru) stru.begin(), stru.end()
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int ans = 0;
        for(char c : s) ans += c == '1';

        bool use = false;
        forr(i, 1, n - 1) {
            if(s[i - 1] == s[i] and s[i - 1] == s[i + 1] and s[i] == '1') {
                ans -= 2;
                use = true;
                break;
            }
        }
        if(!use) forn(i, n - 1) {
            if(s[i] == '1' and s[i] == s[i + 1]) {
                ans -= 1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}