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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), pos(n + 2), neg(n + 2);
    forr(i, 1, n + 1) cin >> v[i];
    v.pb(m);
    
    bool flag = true;
    forr(i, 1, n + 2){
        if(flag) {
            pos[i] = pos[i - 1] + v[i] - v[i - 1];
            neg[i] = neg[i - 1];
        }else{
            neg[i] = neg[i - 1] + v[i] - v[i - 1];
            pos[i] = pos[i - 1];
        }    
        flag = !flag;
    }
    
    int ma = pos[n + 1];
    flag = true;
    forr(i, 1, n + 1){
       
            ma = max(ma, pos[i] - 1 + neg[n + 1] - neg[i]);
  
    }

    cout << ma << '\n';
    
    return 0;
}