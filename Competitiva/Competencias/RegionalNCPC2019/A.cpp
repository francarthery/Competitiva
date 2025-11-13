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

    string s, valid = "?", valid2 = "?"; cin >> s;
    int n; cin >> n;
    vector<string> v(n);
    map<char, int> ini;
    forn(i, n){
        cin >> v[i];
        ini[v[i][0]]++;
    }

    forn(i, n){
        string s2 = v[i];
        if (s.back() == s2[0]) {
            if(valid2 == "?" and (ini[s2.back()] - (s2[0] == s2.back()))) {
                valid2 = s2;
            }
            else if((ini[s2.back()] - (s2[0] == s2.back())) == 0){
                valid = s2;
                valid += '!';
                break;
            }
        }
    }

    if(valid != "?") cout << valid << '\n';
    else cout << valid2 << '\n';

    return 0;
}