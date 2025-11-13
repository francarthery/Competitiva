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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;

        int x = 1, y = 2, z = 3, ans;
        cout << "? " << x << ' ' << y << ' ' << z << endl;
        cin >> ans;
        while(ans != 0){
            int pos = rand() % 3;
            
            if(pos == 0) x = ans;
            else if(pos == 1) y = ans;
            else z = ans;

            cout << "? " << x << ' ' << y << ' ' << z << endl;
            cin >> ans;
            if(ans == -1) return 0;
        }
       
        cout << "! " << x << ' ' << y << ' ' << z << endl;
        
    }   
    
    return 0;
}