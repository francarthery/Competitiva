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
typedef array<int, 3> iii;

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
        vector<vector<int>> nums(4, vector<int>(n+1, 1e9));
        forn(i, n){
            if(s[i] == '0') nums[0][i]=i;
            if(s[i] == '2') nums[1][i]=i;
            if(s[i] == '5') nums[2][i]=i;
            if(s[i] == '6') nums[3][i]=i;
        }
        forn(i, 4) dfor(j, n) {
            nums[i][j] = min(nums[i][j], nums[i][j+1]);
        }

        vector<vector<ii>> ev(n+1); //pos, tipo (0 sumo fijo, 1 escalera ini, 2 escalera fin), monto
        forn(i, n) {
            vector<int> digs{1,0,1,2,3}, pos(5, 1e9);
            forn(j, 5) {
                int ind = i;
                if(j > 2) ind = pos[2];
                else if(j) ind = pos[j-1];
                if(ind <= n) pos[j] = nums[digs[j]][ind];
            }

            if(pos[4] <= pos[3]) { //esta todo bien para adelante
                ev[i].push_back({0, n - i});
                ev[i+1].push_back({1, -1});
            }
            else {
                int mal = min(n, pos[4]) - pos[3];
                ev[i].push_back({0, n - i - mal});
                ev[i+1].push_back({1, -1});
                ev[pos[3]+1].push_back({2, -1});
                if(pos[4] != 1e9) {
                    ev[pos[4]+1].push_back({1, -1});
                }
            }
        }

        ll val = 0, stair = 0;
        vector<ll> ans(n);
        forn(i, n) {
            for(auto &[tipo, monto] : ev[i]) {
                if(tipo == 0) val += monto;
                else if(tipo == 1) stair++;
                else stair--;
            }
            val -= stair;
            ans[i] = val;
        }
        
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }



    return 0;
}