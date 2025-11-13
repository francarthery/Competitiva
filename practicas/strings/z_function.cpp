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

vector<int> z;

void zfunc(string &s){
    int x = 0, y = 0, n = s.size();
    z.resize(n);
    forr(i, 1, n){
        z[i] = (y < i) ? 0 : min(y - i + 1, z[i - x]); //min(escenario 3, escenario 2)
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++; 
        if(i + z[i] - 1 > y){
            x = i; y = i + z[i] - 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s, p;
    cin >> s >> p;

    zfunc(s);
    forr(i, p.size() + 1, s.size()) if(z[i] == p.size()) cout << i - p.size() - 1 << '\n';
    
    return 0;
}