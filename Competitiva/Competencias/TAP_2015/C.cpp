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

    ll n, s, j, d;
    cin >> n >> s >> j >> d;
    string sr; cin >> sr;

    ll s1 = 0, s2 = 0, g1 = 0, g2 = 0;
    for(char c : sr){
        if(c == 'A') g1++;
        else g2++;

        if(g1 >= j and g1 - g2 >= d) g1 = 0, g2 = 0, s1++;
        else if(g2 >= j and g2 - g1 >= d) g1 = 0, g2 = 0, s2++;
    }

    cout << s1 << ' ' << s2 << '\n';


    
    return 0;
}