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
typedef long double ld;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        ld p, r, y; cin >> p >> r >> y; 
        vector<ld> ans;
        ld l = 0, ri = 10, e, w, n, s, ma = 100; //e = 1, w = 2, n = 3, s = 4
        forn(i, 100){
            ld m = (ri + l) / 2.0;

            bool flag = false;
            //w = m
            e = p + m;
            s = (y - r - p - 2 * m) / 2.0;
            n = r + s;
            if(abs(e) <= m and abs(s) <= m and abs(n) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, m, n, s};
                }
                flag = true;
            }

            //w = -m
            e = p - m;
            s = (y - r - p + 2 * m) / 2.0;
            n = r + s;
            if(abs(e) <= m and abs(s) <= m and abs(n) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, -m, n, s};
                }
                flag = true;
            }

            //e = m
            w = m - p;
            s = (y - 2*m - r + p) / 2.0;
            n = r + s;
            if(abs(w) <= m and abs(s) <= m and abs(n) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {m, w, n, s};
                }
                flag = true;
            }

            //e = -m
            w = -m - p;
            s = (y + 2*m - r + p) / 2.0;
            n = r + s;
            if(abs(w) <= m and abs(s) <= m and abs(n) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {-m, w, n, s};
                }
                flag = true;
            }

            //s = m
            n = r + m;
            e = (y - 2*m - r + p) / 2.0;
            w = e - p;
            if(abs(n) <= m and abs(e) <= m and abs(w) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, w, n, m};
                }
                flag = true;
            }

            //s = -m
            n = r - m;
            e = (y + 2*m - r + p) / 2.0;
            w = e - p;
            if(abs(n) <= m and abs(e) <= m and abs(w) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, w, n, -m};

                }
                flag = true;
            }
        
            //n = m
            s = m - r;
            w = (y - 2*m - p + r) / 2.0;
            e = p + w;
            if(abs(s) <= m and abs(w) <= m and abs(e) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, w, m, s};
                }
                flag = true;
            }

            //n = m
            s = -m - r;
            w = (y + 2*m - p + r) / 2.0;
            e = p + w;
            if(abs(s) <= m and abs(w) <= m and abs(e) <= m){
                if(abs(m) < ma){
                    ma = abs(m);
                    ans = {e, w, -m, s};
                }
                flag = true;
            }

            if(flag) ri = m;
            else l = m;
        }

        cout << fixed << setprecision(8) << ans[2] << ' ' << ans[0] << ' ' << ans[3] << ' ' << ans[1] << '\n';
    }

    return 0;
}