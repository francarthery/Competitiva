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

string s; 

int f(int ini){
    int l = ini, r = sz(s) - ini - 1, m;

    while(r - l > 1){
        m = (r + l) / 2;
        vector<int> frec(26);
        forr(i, ini, m + 1) frec[s[i] - 'a']++;
        bool flag = true;

        if(m < sz(s) / 2){
            forr(i, sz(s) - (m + 1), sz(s) - ini) frec[s[i] - 'a']--;
            forn(i, 26) if(frec[i] != 0) flag = false;
            forr(i, m + 1, sz(s) - (m + 1)) if(s[i] != s[sz(s) - i - 1]) flag = false;
        }
        else{
            forr(i, m + 1, sz(s) - ini) frec[s[i] - 'a']--;
            forn(i, 26) if(frec[i] % 2 or frec[i] < 0) flag = false;
        }
        
        if(!flag) l = m;
        else r = m;
    }

    return r - ini + 1;
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
        cin >> s;
        int n = sz(s), mi = 0;
        
        forn(i, n / 2){
            if(s[i] == s[n - i - 1]) continue;

            mi = f(i);
            reverse(all(s));
            mi = min(mi, f(i));
            break;
        }

        cout << mi << '\n';
    }
    
    return 0;
}