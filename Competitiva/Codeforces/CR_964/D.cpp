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

    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        unordered_map<char, deque<int>> m;
        forn(i, sz(s)) m[s[i]].pb(i);

        int pos = 0;
        bool flag = true;
        forn(i, sz(t)){
            int pos1 = 1e6, pos2 = 1e6;
            while(sz(m[t[i]]) and m[t[i]].front() < pos) m[t[i]].pop_front();
            while(sz(m['?']) and m['?'].front() < pos) m['?'].pop_front();

            if(sz(m[t[i]])) pos1 = m[t[i]].front();
            if(sz(m['?'])) pos2 = m['?'].front();

            if(pos1 == pos2) {
                flag = false; 
                break;
            }

            if(pos1 < pos2){
                m[t[i]].pop_front();
                pos = pos1;
            }
            else{
                m['?'].pop_front();
                pos = pos2;
                s[pos2] = t[i];
            }
        }

        for(char &c : s) if(c == '?') c = 'a';
        cout << (flag ? "YES" : "NO") << '\n';
        if(flag) cout << s << '\n';
    }


    
    return 0;
}