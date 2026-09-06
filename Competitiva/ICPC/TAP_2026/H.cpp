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

    // unsigned t0, t1; t0=clock();
    // const int MAXNUM = 1000000;
    // const int MAXN = 13*MAXNUM+1; //puede explotar 1e9+3e8+1
    // vector<bool> criba(MAXN);
    // for(int i = 2; i*i<=MAXN; i++) if(!criba[i]) {
    //     for(int j = 2*i; j < MAXN; j+=i) criba[j] = 1;
    // }
    // criba[1] = criba[0] = 1;
    
    // auto check = [&](int a, int b) {
    //     forn(i, 12) if(criba[a + i*b]) return false;
    //     return true;
    // };

    // ii sol = {0, 0};
    // forr(i, 1, MAXNUM) if(sol == ii(0, 0)) forr(j, 1, MAXNUM) {
    //     if(check(i, j)) {
    //         sol = {i, j};
    //         break;
    //     }
    // }

    // cout << sol.first << ' ' << sol.second << '\n';
    // t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "\nExecution Time: " << time << endl;
    
    
    int n; cin >> n;
    ii sol = {4943, 60060};
    vector<int> ans(13, sol.second);
    ans[0] = sol.first;

    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';



    return 0;
}