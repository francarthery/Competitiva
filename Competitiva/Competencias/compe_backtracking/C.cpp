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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = false;
        map<int, int> m;
        forn(i, n){
            cin >> x;
            m[x % 10]++;
        }

        if(m[0] > 1 and m[3] > 0) flag = true;
        if(m[0] > 0){
            if(m[1] > 0 and m[2] > 0) flag = true;
            else if(m[4] > 0 and m[9] > 0) flag = true;
            else if(m[5] > 0 and m[8] > 0) flag = true;
            else if(m[7] > 0 and m[6] > 0) flag = true;
        }
        if(m[1] > 2) flag = true;
        if(m[1] > 0){
            if(m[6] > 1) flag = true;
            else if(m[5] > 0 and m[7] > 0) flag = true;
            else if(m[8] > 0 and m[4] > 0) flag = true;
            else if(m[3] > 0 and m[9] > 0) flag = true;
        }
        if(m[2] > 0){
            if(m[6] > 0 and m[5] > 0) flag = true;
            else if(m[4] > 0 and m[7] > 0) flag = true;
            else if(m[3] > 0 and m[8] > 0) flag = true;
        }
        if(m[2] > 1 and m[9] > 0) flag = true;
        if(m[3] > 1 and m[7] > 0) flag = true;
        if(m[4] > 1 and m[5] > 0) flag = true;
        if(m[5] > 1 and m[3] > 0) flag = true;
        if(m[9] > 1 and m[5] > 0) flag = true;
        if(m[8] > 1 and m[7] > 0) flag = true;
        if(m[7] > 1 and m[9] > 0) flag = true;
        if(m[8] > 0 and m[9] > 0 and m[6] > 0) flag = true;
        if(m[3] > 0 and m[4] > 0 and m[6] > 0) flag = true;

        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}