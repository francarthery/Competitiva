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

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        cin >> m;
        string s;
        forn(i, m){
            cin >> s;
            bool flag = true;
            unordered_map<char, int> m;
            unordered_map<int, char> m2;
            
            if(s.size() == v.size()){
                forn(i, n){
                    if(m2.count(v[i]) and m2[v[i]] != s[i]) flag = false;
                    else if(!m2.count(v[i])) m2[v[i]] = s[i];

                    if(m.count(s[i]) and m[s[i]] != v[i]) flag = false;
                    else if(!m.count(s[i])) m[s[i]] = v[i];

                    if(!flag) break;
                }
            }
            else flag = false;
            cout << (flag ? "YES" : "NO") << '\n';
        }
    }
    
    return 0;
}