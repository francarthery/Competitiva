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

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        int num = 1, gr = 1;
        for(int i = 1; i < n; i += 2){

            int ind = n;
            forr(j, i, n) if(v[j] != num) {
                ind = j;
                break;
            }

            if(((n - ind + gr) / 2) * 2 >= k) break; //el distinto esta a mi alcance
            num++;
            gr += 2;

            if(i < n - 1 and v[i] == v[i + 1] and k < n) break;
        }

        cout << num << '\n';
    }


    
    return 0;
}