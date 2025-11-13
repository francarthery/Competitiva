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

    int t, rta, n, res;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        rta = INT_MAX;
        vector<int> num(n);
        forn(i, n) {
            cin >> c;
            num[i] = c - '0';
        }

        forn(i, n - 1){ //cuales junto
            num[i] = num[i] * 10 + num[i + 1];
            res = num[0];
            forr(j, 1, n){
                if(j == i + 1) continue;
                if(res < 2 or num[j] < 2) res *= num[j];
                else res += num[j];
            }
            num[i] = (num[i] - num[i + 1]) / 10; 
            rta = min(rta, res);
        }

        cout << rta << '\n';
    }
    
    return 0;
}