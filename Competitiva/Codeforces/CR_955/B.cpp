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

    long long t;
    cin >> t;
    while(t--){
        long long x, y, k;
        cin >> x >> y >> k;

        while(k > 0){
            int val = x % y;
            if(x == 1){
                x += k % (y - 1);
                x %= y;
                break;
            }
            if(k - (y - val) >= 0){
                k -= (y - val);
                x += (y - val);
                while(x % y == 0) x /= y;
                //dbg(x);
            }
            else{
                x += k;
                k = -1;
            }
        }

        cout << x << '\n';
    }

    return 0;
}