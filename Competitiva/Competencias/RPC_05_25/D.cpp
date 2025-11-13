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

    string s, l, res;
    getline(cin, s);
    getline(cin, l);
    set<char> let;
    forr(i, 1, sz(l) - 1) let.insert(l[i]);

    if(!let.count(s[0])) res += s[0];
    forr(i, 1, sz(s)) {
        if(!let.count(s[i]) and s[i] != s[i - 1]) res += s[i]; 
    }
    int ini = 0, fin = sz(res) - 1;
    while(res[ini] == ' ') ini++;
    while(res[fin] == ' ') fin--;

    string res2;
    forr(i, ini, fin) if(res[i] != res[i + 1]) res2 += res[i];
    res2 += res[fin];
    cout << res2 << '\n';


    return 0;
}