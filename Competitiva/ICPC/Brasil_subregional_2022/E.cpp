#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(int)(a);i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=0;i>=0;i--)
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
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
    freopen("input.in","r", stdin);
    freopen("output.out","w", stdout);
    #endif

    int n; cin >> n;
    vector<int> e0, e1;
    forn(i, n) {
        int a, b; cin >> a >> b;
        if(!b) e0.push_back(a);
        else e1.push_back(a);
    }
    reverse(all(e0));
    reverse(all(e1));

    ll time = 0, dir = -1;
    while(sz(e0) or sz(e1)) {
        if(dir == -1) {
            if(sz(e0) and (e1.empty() or e1.back() > e0.back())) {
                time += 10 + max(0ll, (e0.back() - time));
                dir = 0;
                e0.pop_back();
            }
            else {
                time += 10 + max(0ll, (e1.back() - time));
                dir = 1;    
                e1.pop_back();
            }
        }

        while(dir == 0 and sz(e0) and e0.back() < time) {
            time += max(0ll, (e0.back() - (time - 10)));
            e0.pop_back();
        }
        while(dir == 1 and sz(e1) and e1.back() < time) {
            time += max(0ll, (e1.back() - (time - 10)));
            e1.pop_back();    
        } 

        dir = -1;
        // dbg(sz(e0)); dbg(sz(e1));
        // dbg(time);
    }

    cout << time << '\n';

    return 0;
}