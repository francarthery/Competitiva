    #include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define pop(a) (__builtin_popcount((unsigned)a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    unsigned t0, t1; t0=clock();
    const int MAXNUM = 300;
    const int MAXN = 13*MAXNUM+1; //puede explotar 1e9+3e8+1
    vector<bool> criba(MAXN);
    for(int i = 2; i*i<=MAXN; i++) if(!criba[i]) {
        for(int j = 2*i; j < MAXN; j+=i) criba[j] = 1;
    }
    criba[1] = criba[0] = 1;

    // cout << "termine\n";

    // int n; cin >> n;
    
    auto f = [&](vector<int> &v, int n) -> bool {
        vector<vector<bool>> dp(n+1, vector<bool>(1<<n));

        vector<vector<int>> masks(n+1);
        forn(i, (1<<n)) masks[pop(i)].push_back(i);
        
        forr(i, 1, n+1) {
            forn(j, sz(masks[i])) {
                int mask = masks[i][j];
                int sum = 0;
                forn(k, n) if(mask & (1 << k)) sum += v[k];
                dp[i][mask] = criba[sum];

                for(int submask = mask; submask>0; submask = (submask-1)&mask) {
                    int comp = mask ^ submask;
                    dp[i][mask] = dp[i][mask] or dp[pop(comp)][comp] and dp[pop(submask)][submask];
                }
            }
        }
        return dp[n][(1<<n)-1];
    };  

    int n = 13;
    cout << "vector<vector<int>> v{\n";

    // vector<vector<int>> test;
    // auto make = [&](auto &&f, vector<int> &v, int mi) -> void{
    //     if(sz(v) == n) {
    //         test.push_back(v);
    //         return;
    //     }
    //     forr(i, mi, MAXNUM) {
    //         v.push_back(i+1);
    //         f(f, v, i);
    //         v.pop_back();
    //     }
    // };
    // vector<int> ini;
    // make(make, ini, 0);
    
    vector<int> test(11, 1);
    forn(i, 1000) {    
        test.push_back(i+1);
        if(!f(test, sz(test))) {
            cout << '{';
            cout << test[0];
            forr(k, 1, i) cout << ',' << test[k];
            cout << "}" << endl;
            break;
        }
        // vdbg(test);
        test.pop_back();
    }
    
    cout << '}';

    t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "\nExecution Time: " << time << endl;


    return 0;
}