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
        string s;
        cin >> s;
        ll cont2 = 0, cont3 = 0, sum = 0;
        for(char &c : s){
            sum += c - '0';
            if(c == '2') cont2++;
            else if(c == '3') cont3++;
        }

        cont2 = min(cont2, 8ll);
        cont3 = min(cont3, 2ll);
        bool flag = sum % 9 == 0;
        forn(i, cont2 + 1){
            forn(j, cont3 + 1){
                if((sum + i * 2 + j * 6) % 9 == 0) {
                    flag = true;
                    break;
                }
            }
        }

        cout << (flag ? "YES" : "NO" ) << '\n';
    }

    
    return 0;
}