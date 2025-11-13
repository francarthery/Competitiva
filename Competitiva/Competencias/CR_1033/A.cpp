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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        bool flag = false;
        if(l1 == l2 + l3 and b2 == b3 and b2 + b1 == l1) flag = true;
        else if(b1 == b2 + b3 and l2 == l3 and l2 + l1 == b1) flag = true;
        else if(b1 == b2 and b1 == b3 and l1 + l2 + l3 == b1) flag = true;
        else if(l1 == l2 and l1 == l3 and b1 + b2 + b3 == l1) flag = true;

        cout << (flag ? "YES" : "NO") << '\n';


    }



    return 0;
}