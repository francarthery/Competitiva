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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, x;
        bool flag = true;
        cin >> n;
        vector<int> v(n);
        cin >> x;
        v[x - 1] = 1;
        forr(i, 1, n){
            bool temp = false;
            cin >> x;
            v[x - 1] = 1;
            if(x > 1 and v[x - 2]) temp = 1;
            if(x < n and v[x]) temp = 1;
            if(!temp){
                flag = false;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}