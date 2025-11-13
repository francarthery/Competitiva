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

    int t, n, x, y;
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        vector<int> v(n);

        if(n == 4 and y - x == 2){
            v[x - 1] = 1;
            v[y - 1] = 2;
        }
        else{
            v[x - 1] = 1; 
            v[y - 1] = 0;

            int ini1, ini2;
            if((y - x) % 2) ini1 = x;
            else {
                if(y - x) v[x] = 2;
                ini1 = x + 1;
            }

            if((n - y + x - 1) % 2){
                if(n - y + x - 1 == 1) {
                    v[y % n] = 2;
                    ini2 = (y + 1) % n;
                }
                else{
                    v[y % n] = 1; v[(y + 1) % n] = 2; v[(y + 2) % n] = 0;
                    ini2 = (y + 3) % n;
                }
            }
            else ini2 = y % n;

            bool flag = 0;
            forr(i, ini1, y){
                v[i] = flag;
                flag = !flag;
            }
            flag = 1;
            for(int i = ini2; i != x; i = (i + 1) % n){
                v[i] = flag;
                flag = !flag;
            }
        }

        forn(i, n) cout << v[i] << ' ';
        cout << '\n';

    }


    
    return 0;
}