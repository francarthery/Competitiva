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

    int t;
    cin >> t;
    while(t--){
        vector<int> v(5);
        cin >> v[0] >> v[1] >> v[3] >> v[4];

        int rta = 0, ma = 1;
        v[2] = v[0] + v[1];
        forn(i, 3) if(v[i] + v[i + 1] == v[i + 2]) rta++;
        ma = max(ma, rta);

        rta = 0;
        v[2] = v[3] - v[1];
        forn(i, 3) if(v[i] + v[i + 1] == v[i + 2]) rta++;
        ma = max(ma, rta);

        rta = 0;
        v[2] = - v[3] + v[4];
        forn(i, 3) if(v[i] + v[i + 1] == v[i + 2]) rta++;
        ma = max(ma, rta);

        cout << ma << '\n';
    }

    return 0;
}