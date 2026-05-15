#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) for(auto &e: x) cout<<"[";for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    set<int> s;
    forn(i, n) s.insert(i);
    s.insert(1e9);

    forn(i, k) {
        int h; cin >> h;
        auto it = s.lower_bound(h);

        int l = -1e9, r = *it;
        if(it != s.begin()) l = *prev(it);

        if(abs(l - h) <= abs(r - h)) {
            cout << l << '\n';
            s.erase(l);
        }
        else {
            cout << r << '\n';
            s.erase(r);
        }
    }



    return 0;
}