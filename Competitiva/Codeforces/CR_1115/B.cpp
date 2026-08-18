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

        char ant = '#';
        int sobra0 = 0, sobra1 = 0;
        for(char c : s) {
            if(ant == c) {
                if(c == '0') sobra0++;
                else sobra1++;
            }
            ant = c;
        }

        int ans = sobra0 + sobra1;
        int dif = sobra1 - sobra0;

        // dbg(sobra1); dbg(sobra0);
        if(abs(dif) > 1) {
            if(dif == -2 and (s[0] == '1' or s.back() == '1')) ans+=1;
            else if(dif == -3 and s[0] == '1' and s.back() == '1') ans+=2;
            else if(dif == 2 and (s[0] == '0' or s.back() == '0')) ans+=1;
            else if(dif == 3 and s[0] == '0' and s.back() == '0') ans+=2;
            else ans = -1;
        }

        cout << ans << '\n';
    }



    return 0;
}