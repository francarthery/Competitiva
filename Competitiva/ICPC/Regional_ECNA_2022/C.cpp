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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ll> v1(n), v2(14);
    char c;
    map<char, int> m{{'A', 1}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};

    forn(i, n){
        cin >> c; 
        if(isdigit(c)) {
            v1[i] = c - '0';
            v2[c - '0']++;
        }
        else{
            v2[m[c]]++;
            if(c == 'A') v1[i] = 1;
            else v1[i] = 10;
        }
    }

    ll cant2 = 0, cant3 = 0;
    vector<ll> dp(16);
    dp[0] = 1;
    forn(i, n) dfor(j, 16) if(j - v1[i] >= 0) dp[j] += dp[j - v1[i]];

    for(int i : v2) cant2 += i * (i - 1);
    
    ll ini = 1, tam = 1;
    while(!v2[ini]) ini++;
    ll ant = ini, prod = v2[ini];
    forr(i, ++ini, 14) {
        if(v2[i]){
            tam++;
            prod *= v2[i];
            if(!v2[i - 1]) prod = v2[i];
        } 
        else{
            if(tam >= 3) cant3 += tam * prod;
            tam = 0;
        }
    }
    if(v2[13] and tam >= 3) cant3 += tam * prod;

    //dbg(dp[15]); dbg(cant2); dbg(cant3);
    cout << dp[15] * 2 + cant2 + cant3 << '\n';

    return 0;
}