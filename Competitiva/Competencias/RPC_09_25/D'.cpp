#include<bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(a) ((int)(a.size()))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) <<endl;
#define vdbg(x) {cout <<"["; for(auto i:x){cout << i << ", "; cout << "]" <<endl; }}
#define ws <<' '<<
#define nl cout<<endl;
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ld p, q, y; cin >> p >> q >> y;
        ld e,w,n,s;
        vector<ld> ans;

        ld lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            s = mi;
            w = (y-p-q-2*s) / 2.0
            ;
            e = p+w;
            n = q+s;
            if(abs(w) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }
        //dbg(lo);
        //dbg(hi);
        vector<ld> ans1 = {n,e,s,w};
        vector<ld> abs1(4);
        forn(i,4){
            abs1[i] = abs(ans1[i]);
        }
        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            s = -mi;
            w = (y-p-q-2*s) / 2.0;
            e = p+w;
            n = q+s;
            if(abs(w) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }

        vector<ld> ans2 = {n,e,s,w};
        vector<ld> abs2(4);
        forn(i,4){
            abs2[i] = abs(ans2[i]);
        }

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            w = mi;
            s = (y-p-q-2*w) / 2.0;
            e = p+w;
            n = q+s;
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }

        vector<ld> ans3 = {n,e,s,w};
        vector<ld> abs3(4);
        forn(i,4){
            abs3[i] = abs(ans3[i]);
        }

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            w = -mi;
            s = (y-p-q-2*w) / 2.0;
            e = p+w;
            n = q+s;
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }

        vector<ld> ans4 = {n,e,s,w};
        vector<ld> abs4(4);
        forn(i,4){
            abs4[i] = abs(ans4[i]);
        }

        ld mx1 = *max_element(all(abs1));
        ld mx2 = *max_element(all(abs2));
        ld mx3 = *max_element(all(abs3));
        ld mx4 = *max_element(all(abs4));
        
        ld mx = max(mx1, max(mx2, max(mx3, mx4)));
        if(abs(mx - mx1) <= 1e-8){
            cout << ans1[0];
            forr(i,1,4){
                cout << ' ' << ans1[i];
            }
            nl;
            return 0;
        }
        if(abs(mx - mx2) <= 1e-8){
            cout << ans2[0];
            forr(i,1,4){
                cout << ' ' << ans2[i];
            }
            nl;
            return 0;
        }
        if(abs(mx - mx3) <= 1e-8){
            cout << ans3[0];
            forr(i,1,4){
                cout << ' ' << ans3[i];
            }
            nl;
            return 0;
        }
        if(abs(mx - mx4) <= 1e-8){
            cout << ans4[0];
            forr(i,1,4){
                cout << ' ' << ans4[i];
            }
            nl;
            return 0;
        }
        
    }

    return 0;

}