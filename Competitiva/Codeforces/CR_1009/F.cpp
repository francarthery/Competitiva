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


int f(int s, int lim){
    forn(i, 31){
        if((1 << (i + 1)) > lim or s & (1 << i)) return (1 << i);
    }
    return 0;
}

int pepe(int a, int b){
    int sum = 0;
    forn(i, 25){
        if((1 << i) & a) sum += b / (1 << i);
    }
    return sum;
}

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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        ll res = 0;
        while(r1 - l1 and r2 - l2){
            int a1 = f(l1, r1 - l1), a2 = f(l2, r2 - l2);
            if(a1 < a2){
                res += (r2 - l2) / a1;
                res += pepe((r2 - l2) % a1, a1);
                l1 += a1;
            }
            else{
                res += (r1 - l1) / a2;
                res += pepe((r1 - l1) % a2, a2);
                l2 += a2;
            }            
        }

        cout << res << '\n';
    }


    
    return 0;
}