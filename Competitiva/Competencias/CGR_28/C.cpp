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
        string s, s1;
        cin >> s;
        s1 = s;
        for(char &c : s1){
            if(c == '0') c = '1';
            else c = '0';
        }

        int ind = -1;
        forn(i, sz(s)){
            if(s[i] == '0'){
                ind = i;
                break;
            }
        }
        
        if(ind != -1){
            ll ma = 0, ind2 = -1;
            string s2(sz(s1) - ind, '#');

            forn(i, ind){
                ll cont = 0;
                forn(j, sz(s1) - ind){
                    if(s[ind + j] == s1[i + j] and s2[j] != s[ind + j]) {
                        s2 = s1.substr(i, sz(s1) - ind);
                        ind2 = i; //intervalo de largo sz(s1) - ind a usar
                    }
                    else if(s[ind + j] != s1[i + j] and s2[j] == s[ind + j]) break;
                }
            }
            cout << 1 << ' ' << sz(s1) << ' ' << ind2 + 1 << ' ' << sz(s1) - ind + ind2 << '\n';
        }
        else cout << 1 << ' ' << sz(s1) << ' ' << 1 << ' ' << 1 << '\n';

    }


    
    return 0;
}