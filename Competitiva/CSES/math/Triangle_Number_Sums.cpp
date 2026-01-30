#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector<ll> nums{1}; //https://en.wikipedia.org/wiki/Fermat_polygonal_number_theorem
    ll sum = 2;
    while(nums.back() <= 1e12) {
        nums.pb(nums.back() + sum++);
    }

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        int ans = (binary_search(all(nums), n) ? 1 : 3); 
        int r = upper_bound(all(nums), n) - nums.begin();

        if(ans > 1) forn(i, sz(nums)) {
            while(i <= r and nums[i] + nums[r] > n) r--;
            if(nums[i] + nums[r] == n) {
                ans = 2;
                break;
            } 
            if(i > r) break;
        }

        cout << ans << '\n';
    }


    return 0;
}