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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;

        int i = 0, ans = 0;
        while(i < n) {
            if(a[i] == b[i]) i++;
            else if(i < n-1 and (a[i] == a[i+1] or b[i] == b[i+1])) {
                if(a[i] != a[i+1]) ans++;
                else if(b[i] != b[i+1]) ans++;
                i+=2;
            }
            else ans+=1, i++;
        }

        cout << ans << '\n';
    }

    return 0;
}