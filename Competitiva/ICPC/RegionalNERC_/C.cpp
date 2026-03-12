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

int n;
string s;
vector<vector<int>> dp;

int solve(int l, int r, int cont, bool t){ //0 Poly, 1 Mono
    if(l > r) return 0;
    if(dp[l][r]) return dp[l][r];
    if(cont < 0) return 1e9;

    if(t){
        dp[l][r] = min(
            abs(solve(l + 1, r, cont + (s[l]=='(' ? 1 : -1), 0) + (s[l]=='(' ? 1 : -1)), 
            abs(solve(l, r - 1, cont + (s[r]=='(' ? 1 : -1), 0) + (s[r]=='(' ? 1 : -1))
        );
    }else{
        dp[l][r] = max(abs(solve(l + 1, r, cont, 1)), abs(solve(l, r - 1, cont, 1)));
    }

    return dp[l][r];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;

    while(t--){
        cin >> n;
        cin >> s;
        dp.resize(n, vector<int> (n, -1));
        int win=1e9;

        //cnt, l, r
        set<vector<int>> pqmax;
        set<vector<int>> pqmin; 
        vector<vector<int>>vstmax(n, vector<int>(n,-1e9)), vstmin(n, vector<int>(n,1e9));

        if(s[0] != ')') {
            vstmax[1][n-1]=1;
            pqmax.insert({1,n-1});
        }
        if(s[n - 1] != ')') {
            vstmax[0][n-2]=1;
            pqmax.insert({0,n-2});
        }


        int f=0;
        while(!f && (pqmax.size() || pqmin.size())){
            while(!f && pqmax.size()){
                auto vec = *pqmax.rbegin();
                pqmax.erase(prev(pqmax.end()));
                int l=vec[0];
                int r=vec[1];
                if(l>r)continue;
                if(vstmax[l][r]==0) {
                    cout<<"Monocarp"<<endl;
                    f=1;
                    break;
                }
                int cntl = vstmax[l][r] + s[l]=='('?1:-1;
                if(l+1<n && cntl < vstmin[l+1][r]){
                    vstmin[l+1][r]=cntl;
                    pqmin.insert({l+1,r});
                }
                int cntr = vstmax[l][r] + s[r]=='('?1:-1;
                if(r-1>=0 && cntr < vstmin[l][r-1]){
                    vstmin[l][r-1]=cntr;
                    pqmin.insert({l,r-1});
                }
            }
            while(!f && pqmin.size()){
                auto vec = *pqmin.begin();
                pqmin.erase(pqmin.begin());
                int l=vec[0];
                int r=vec[1];
                if(l>r)continue;
                if(vstmin[l][r]==0) {
                    f=1;
                    cout<<"Monocarp"<<endl;
                    break;
                }
                int cntl = vstmin[l][r] + s[l]=='('?1:-1;
                if(cntl == 0){
                     f=1;
                    cout<<"Monocarp"<<endl;
                    break;
                }
                if(l+1<n && cntl > vstmax[l+1][r]){
                    vstmax[l+1][r]=cntl;
                    pqmax.insert({l+1,r});
                }
                int cntr = vstmin[l][r] + s[r]=='('?1:-1;
                if(cntr == 0){
                     f=1;
                    cout<<"Monocarp"<<endl;
                    break;
                }
                if(r-1 >= 0 && cntr > vstmax[l][r-1]){
                    vstmax[l][r-1]=cntr;
                    pqmax.insert({l,r-1});
                }   
            }
        }
        if (f) continue;
        cout << "Polycarp" << '\n';
    }



    return 0;
}