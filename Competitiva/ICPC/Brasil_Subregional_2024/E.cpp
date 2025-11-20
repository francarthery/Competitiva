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

int dig(int n){
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
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

    ll n, k, x; cin >> n >> k;
    vector<int> sumd(1e6 + 1);
    vector<int> v(1e6 + 1);
    forn(i, 1e6) sumd[i + 1] = dig(i + 1);

    forn(i, n) {
        cin >> x;
        v[x]++;
    }

    dfor(i, 1e6 + 1){      
        k -= v[i];

        if(k <= 0){
            cout << sumd[i] << '\n';
            return 0;
        }
        
        v[i - sumd[i]] += v[i];
    }

    cout << 0 << '\n';



    return 0;
}