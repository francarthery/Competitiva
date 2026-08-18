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
typedef ll tipo;

struct FenwickTree {
    int N;            // maybe replace vector with unordered_map when "many 0s"
    vector<tipo> ft;  // for more dimensions, make ft multi-dimensional
    FenwickTree(int n) : N(n), ft(n + 1) {}
    void upd(int i0, tipo v) {  // add v to i0th element (0-based)
        // add extra fors for more dimensions
        for (int i = i0 + 1; i <= N; i += i & -i) ft[i] += v;
    }
    tipo get(int i0) {  // get sum of range [0,i0)
        tipo r = 0;       // add extra fors for more dimensions
        for (int i = i0; i; i -= i & -i) r += ft[i];
        return r;
    }
    tipo get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
        return get(i1) - get(i0);
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> stb(n);
        vector<vector<int>> mat(n, vector<int>(m));
        multiset<int> s;
        forn(i, n) cin >> stb[i];

        ll mi = m; 

        forn(i, n) forn(j, m) cin >> mat[i][j];

        dfor(i, n) {
            forn(j, m) s.insert(mat[i][j]);           

            ll sum = 0, cont = 0;
            for(auto it = s.rbegin(); it != s.rend() and cont < mi; it++) {
                sum += *it;
                cont++;
                if(sum >= stb[i]) {
                    mi = min(mi, cont);
                    break;
                }
            }
        }

        cout << mi << '\n';
    }



    return 0;
}