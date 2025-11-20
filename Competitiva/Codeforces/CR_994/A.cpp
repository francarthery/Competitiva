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
        int n, x, rta = 1;
        cin >> n;
        deque<int> d(n);
        forn(i, n) cin >> d[i];
        while(!d.empty() and d.front() == 0) d.pop_front();
        while(!d.empty() and d.back() == 0) d.pop_back();

        bool cero = false, todo0 = true;
        forn(i, sz(d)) {
            if(d[i] == 0) cero = true;
            else todo0 = false;
        }
        if(todo0) cout << 0;
        else if(cero) cout << 2;
        else cout << 1;
        cout << '\n';
    }


    
    return 0;
}