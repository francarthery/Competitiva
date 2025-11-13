#include<bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(a) ((int)(a.size()))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) <<endl;
#define vdbg(x) {cout <<"["; for(auto i:x){cout << i << ", "; }cout << "]" <<endl; }
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

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            e = mi;
            w = -p+e;
            s = (y-p-q-2*w)/2.0;
            n = q+s;
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }
        vector<ld> ans5 = {n,e,s,w};
        vector<ld> abs5(4);
        forn(i,4){
            abs5[i] = abs(ans5[i]);
        }

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            e = -mi;
            w = -p+e;
            s = (y-p-q-2*w)/2.0;
            n = q+s;
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }
        vector<ld> ans6 = {n,e,s,w};
        vector<ld> abs6(4);
        forn(i,4){
            abs6[i] = abs(ans6[i]);
        }

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            n = mi;
            s = -q+n;
            w = (y-p-q-2*s)/2.0;
            e = p+w;
            
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }
        vector<ld> ans7 = {n,e,s,w};
        vector<ld> abs7(4);
        forn(i,4){
            abs7[i] = abs(ans7[i]);
        }

        lo = 0, hi = 1;
        forr(i,0,100){
            ld mi = (lo + hi) / 2.0;
            n = -mi;
            s = -q+n;
            w = (y-p-q-2*s)/2.0;
            e = p+w;
            
            if(abs(s) > mi || abs(e) > mi || abs(n) > mi){
                lo = mi;
            } else {
                hi = mi;
            }
        }
        vector<ld> ans8 = {n,e,s,w};
        vector<ld> abs8(4);
        forn(i,4){
            abs8[i] = abs(ans8[i]);
        }
        
        
        cout << fixed << setprecision(10);

        ld mx1 = *max_element(all(abs1));
        ld mx2 = *max_element(all(abs2));
        ld mx3 = *max_element(all(abs3));
        ld mx4 = *max_element(all(abs4));
        ld mx5 = *max_element(all(abs5));
        ld mx6 = *max_element(all(abs6));
        ld mx7 = *max_element(all(abs7));
        ld mx8 = *max_element(all(abs8));

    
        
        ld mx = min(mx1, min(mx2, min(mx3, min(mx4, min(mx5, min(mx6, min(mx7, mx8)))))));
        if(abs(mx - mx1) <= 1e-8){
            cout << ans1[0];
            forr(i,1,4){
                cout << ' ' << ans1[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx2) <= 1e-8){
            cout << ans2[0];
            forr(i,1,4){
                cout << ' ' << ans2[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx3) <= 1e-8){
            cout << ans3[0];
            forr(i,1,4){
                cout << ' ' << ans3[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx4) <= 1e-8){
            cout << ans4[0];
            forr(i,1,4){
                cout << ' ' << ans4[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx5) <= 1e-8){
            cout << ans5[0];
            forr(i,1,4){
                cout << ' ' << ans5[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx6) <= 1e-8){
            cout << ans6[0];
            forr(i,1,4){
                cout << ' ' << ans6[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx7) <= 1e-8){
            cout << ans7[0];
            forr(i,1,4){
                cout << ' ' << ans7[i];
            }
            nl;
            continue;
        }
        if(abs(mx - mx8) <= 1e-8){
            cout << ans8[0];
            forr(i,1,4){
                cout << ' ' << ans8[i];
            }
            nl;
            continue;
        }
        
    }

    return 0;

}