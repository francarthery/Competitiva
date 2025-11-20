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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 2 and n < 27) cout << "-1";
        else{
            if(n % 2 == 0){
                forn(i, n / 2){
                    cout << i + 1 << ' ' << i + 1 << ' ';
                }
            }

            else{
                forr(i, 1, 10) cout << i << ' ';
                forr(i, 1, 10) cout << i << ' ';
                cout << "10 10 11 11 12 13 13 1 12 ";
                forn(i, (n - 27) / 2) cout << i + 14 << ' ' << i + 14 << ' ';
            }
        }
        cout << '\n';
    }

    
    return 0;
}