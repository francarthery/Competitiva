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
#define vdbg(x) {cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";}
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
        int x, ult = -1;
        vector<bool> reach(n);
        vector<int> punt(3, -1);
        vector<char> let{'q', 'k', 'j'};
        vector<pair<char, int>> padre(n, pair('#', -1));
        priority_queue<int, vector<int>, greater<int>> res;
        vector<vector<int>> v(3, vector<int>(n)), v2(3, vector<int>(n));
        
        forn(i, 3){
            forn(j, n){
                cin >> x;
                v[i][x - 1] = j + 1;
                v2[i][j] = x;
            }    
        }

        res.push(0); reach[0] = true;
        while(!res.empty() and !reach[n - 1]){
            int elem = res.top();
            res.pop();

            forn(i, 3){
                if(v2[i][elem] - 1 > punt[i] and elem >= ult){
                    forr(j, punt[i] + 1, v2[i][elem]){
                        if(!reach[v[i][j] - 1]){
                            padre[v[i][j] - 1] = {let[i], elem};
                            reach[v[i][j] - 1] = true;
                            res.push(v[i][j] - 1);
                        }
                    }
                    punt[i] = v2[i][elem] - 1;
                    ult = elem;
                }
            }
        }

        if(reach[n - 1]) {
            pair<char, int> act = padre[n - 1];
            vector<pair<char, int>> ans{{act.fr, n - 1}};
            while(act.sc != 0){
                ans.pb({padre[act.sc].fr, act.sc});
                act = padre[act.sc];
            }

            cout << "YES\n";
            cout << sz(ans) << '\n';
            dfor(i, sz(ans)) cout << ans[i].fr << ' ' << ans[i].sc + 1 << '\n';
        }
        else cout << "NO\n";
    }
    
    return 0;
}

