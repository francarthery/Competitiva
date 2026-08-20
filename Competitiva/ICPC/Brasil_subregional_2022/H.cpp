#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<x<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<vector<int>> nums(k), inds(k);
    forn(i, n){
        int x, y; cin >> x >> y; y--;
        nums[y].push_back(x);
        inds[y].push_back(i);
    }

    forn(i, k){
        sort(all(nums[i]));
        sort(all(inds[i]));
    }
 
    vector<int> ans(n);

    forn(i, k){
        forn(j, sz(nums[i])){
            ans[inds[i][j]] = nums[i][j];
        }
    }

    forr(i, 1, n){
        if(ans[i] < ans[i - 1]){
            cout << "N" << '\n';
            return 0;
        }
    }

    cout << "Y" << '\n';
    return 0;
}