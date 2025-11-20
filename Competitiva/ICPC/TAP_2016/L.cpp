#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

bool flag = true;
int n, k;
vector<int> v;

void dfs(int ind, int sum){
    if(ind + sum < 0 or ind + sum >= k) return;
    if(v[ind] > 2 and v[ind] - v[ind + sum] < 3 and v[ind] - v[ind + sum] > 0) dfs(ind + sum, sum);
    else{
        flag = false;
        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    cin >> n >> k;
    v.resize(k);
    forn(i, k) cin >> v[i];
    int ind = 0, ma = 0;
    forn(i, k){
        if(v[i] > ma){
            ma = v[i];
            ind = i;
        }
    }

    if(ma > n) flag = false;
    else if(ind < k - 1 and ind > 0 and (v[ind + 1] == v[ind - 1] or v[ind + 1] + v[ind - 1] != 2 * v[ind] - 3)) flag = false;
    else if(ind == k - 1 and (v[ind] < 3 or abs(v[ind] - v[ind - 1]) > 2 or v[ind] == v[ind - 1])) flag = false;
    else if(ind == 0 and (v[ind] < 3 or abs(v[ind] - v[ind + 1]) > 2 or v[ind] == v[ind + 1])) flag = false;
    if(flag){
        if(ind < k - 1) dfs(ind + 1, 1);
        if(ind > 0) dfs(ind - 1, -1);
    }

    cout << (flag ? "S" : "N") << '\n';
    
    return 0;
}