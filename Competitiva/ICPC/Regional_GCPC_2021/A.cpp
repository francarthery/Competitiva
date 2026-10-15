#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end();
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "<<;for(auto e : x) cout<<e<<" ";cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    ll n; cin >> n;
    ll ans = -1;
    if(n==1 or n==3) ans = 1;
    else if(n==5) ans = 3;
    else {
        ll target = (n+1)/2-2;
        // dbg(target);
        vector<ll> nums{0};
        while(nums.back() < 1e18) {
            nums.push_back(nums.back()*2ll+1ll);
        }

        forn(i, sz(nums)) forn(j, sz(nums)) {
            if(nums[i] + nums[j] + 1 == target) ans = (nums[i]+1ll) * 2ll+1ll;
        }
        // for(auto i : nums) cout << i << ' ';
    }

    if(ans==-1) cout << "impossible\n";
    else cout << ans << '\n';

    return 0;
}