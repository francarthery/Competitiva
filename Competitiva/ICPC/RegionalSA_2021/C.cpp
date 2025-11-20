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

    int n, sum = 0;
    cin >> n;
    vector<int> v(n), pre(n * 2 + 1), pre2(n * 2 + 1);
    forn(i, n) {
        cin >> v[i];
        sum += v[i];
    }
    sum /= n;
    forr(i, 1, 1 + n * 2){
        pre[i] = pre[i - 1] + v[(i - 1) % n] - sum;
        pre[i] = max(pre[i], 0);
        pre2[i] = pre2[i - 1] + pre[i];
    }

    forn(i, n * 2) cout << v[i % n] - sum << ' ';
    cout << '\n';
    forr(i, 1, 1 + n * 2) cout << pre[i] << ' ';
    cout << '\n';
    forr(i, 1, 1 + n * 2) cout << pre2[i] << ' ';

    int mi = INT_MAX, sum = 0;
    forn(i, n) sum += pre2[i];
    forn(i, n){
        
    }
    
    return 0;
}