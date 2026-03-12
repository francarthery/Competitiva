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
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        map<char, ll> frec;
        for(char c : s) frec[c]++;

        char ant = '#';
        ll ans = 1, seg = 0;
        forn(i, sz(s)) {
            if(s[i] == ant) seg++;
            else {
                ans -= (seg * (seg - 1)) / 2;
                seg = 1;
            }

            ant = s[i];
        }

        ans -= (seg * (seg - 1)) / 2;
        for(auto i : frec) ans += (i.second * (i.second + 1)) / 2;

        cout << ans << '\n';
    }    

    return 0;
}