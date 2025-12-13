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
    cout << '[';
    for(auto c : v) cout << c << ',';
    cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int n, m;
vector<int> co;
unordered_set<int> s;

void f(int i, vector<int> &v){
    if(i == n){
        int ans = 0;
        forn(j, n) ans += co[j] * v[j];
        s.insert(ans);
        return;
    }

    for(int j = 1; j <= m; j++){
        v.pb(j);
        f(i + 1, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif    

    while(cin >> n >> m){
        s.clear();
        co.resize(n);
        vector<int> v;
        forn(i, n) cin >> co[i];
        
        f(0, v);
		cout << s.size() << '\n';
        cout << (s.size() == (int)pow(m, n) ? "Lucky Denis!" : "Try again later, Denis...") << '\n';
    }


    
    return 0;
}