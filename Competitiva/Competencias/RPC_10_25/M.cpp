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

    int n, k; cin >> n >> k;
    vector<int> v(n);
    map<int, vector<int>> frec;
    forn(i, n) {
        cin >> v[i];
        frec[v[i]].pb(i);
    }

    int mex = 0;
    for(auto i : frec){
        if(i.fr != mex) break;

        int ind = 0, ini = 0; //ini es abierto
        while(ind < sz(i.sc)){
            if(i.sc[ind] < ini) {
                mex++;
                break;
            }
            ind = upper_bound(all(i.sc), i.sc[ind] + k - 1) - i.sc.begin();

            int mi = max(i.sc[ind - 1] - k + 1, ini);
            ini = mi + 2 * k;
        }   
    }

    cout << mex << '\n';

    return 0;
}