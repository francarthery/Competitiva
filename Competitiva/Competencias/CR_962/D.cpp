#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, x, t;
    cin >> t;
    while(t--){
        ll rta = 0;
        int temp1, temp2;
        cin >> n >> x;
        forr(i, 1, n){
            forr(j, 1, n){
                if(i * j > n or i + j > x) break;
                temp1 = (n - (i * j)) / (i + j);
                temp2 = x - i - j;
                rta += min(temp1, temp2); 
            }
        }

        cout << rta << '\n';
    }    
    
    return 0;
}