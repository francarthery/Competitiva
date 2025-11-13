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

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    ii best[1 << n];
    best[0] = {1, 0};

    forr(s, 1, (1 << n)){
        best[s] = {n + 1, 0};
        forn(p, n){
            if(s & (1 << p)){
                ii option = best[s ^ (1 << p)];
                if(option.sc + v[p] <= x){
                    option.sc += v[p];
                }
                else{
                    option.fr++;
                    option.second = v[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }

    cout << best[(1 << n) - 1].fr << '\n';

    return 0;
}