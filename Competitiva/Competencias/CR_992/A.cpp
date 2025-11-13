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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
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

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        bool flag = false;
        int num = -1;
        forn(i, n){
            forn(j, n){
                if(i != j){
                    if(abs(v[i] - v[j]) % k == 0) flag = true;
                }
            }
            if(!flag) {
                num = i + 1;
                break;
            }
            flag = false;
        }

        if(num != -1){
            cout << "YES\n";
            cout << num << '\n';
        }
        else cout << "NO\n";

    }


    
    return 0;
}