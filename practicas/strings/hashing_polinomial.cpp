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

const int a = 31, b = 1e9 + 7;
vector<ll> p, h;

void Hash(string &s){
    p.resize(s.size());
    h.resize(s.size());

    p[0] = 1;
    h[0] = s[0];
    for(int i = 1; i < s.size(); i++) {
        h[i] = (h[i - 1] * a + s[i]) % b;
        p[i] = (p[i - 1] * a) % b;
    }
}

ll gethash(int l, int r){
    if(l == 0) return h[r];
    else return ((h[r] - h[l - 1] * p[r - l + 1]) % b + b) % b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        //freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s = "pasapas";
    Hash(s);
    cout << gethash(0, 2) << ' ' << gethash(4, 6) << '\n';

    return 0;
}