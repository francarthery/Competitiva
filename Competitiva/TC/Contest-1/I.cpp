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
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    string s;
    forn(tt, t){
        cin >> s;
        int cont = 0;
        bool flag = false;
        map<int, int> f;
        for(char &c: s){
            f[c - '0']++;
            cont += c - '0';
        }

        if(cont % 3 == 0 and f[0] > 0){
            if(f[0] == 1 and (f[2] > 0 or f[4] > 0 or f[6] > 0 or f[8] > 0)) flag = true;
            else if(f[0] > 1) flag = true;
        }

        cout << (flag ? "red" : "cyan") << '\n';
    }
    
    return 0;
}