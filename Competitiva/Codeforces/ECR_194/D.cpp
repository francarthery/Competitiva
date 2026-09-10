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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        bool es1 = true, dosceros = false, es3 = false;
        char ant = s[0];

        for(char c : s) {
            if(c == '+' and ant == '-' or c == '-' and ant == '+') es1 = false;
            if(c == ant and c == '0') dosceros = true;
            ant = c;
        }

        int contmas = 0, contmen = 0;
        forn(i, n-2) {
            if((i==0 or contmen % 2 == 0) and s.substr(i, 3) == "--0") es1 = false;
            if((i==0 or contmas % 2 == 0) and s.substr(i, 3) == "++0") es1 = false;
            if(s[i] == '+') contmas++, contmen = 0;
            else if(s[i] == '-') contmen++, contmas = 0;
            else contmen = contmas = 0;
        }

        set<string> m{"+--+", "-++-"};
        forn(i, n - 3) if(m.count(s.substr(i, 4))) es3 = true;
        
        if(dosceros) cout << -1 << '\n';
        else if(es1) cout << 1 << '\n';
        else if(!es3) cout << 2 << '\n';
        else cout << 3 << '\n';
    }



    return 0;
}