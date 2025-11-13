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

vector<int> pi(2 * 1e5);

int kmp(string &s, int m) {
    int n = sz(s), j = 0, rta = 0;

    for (int i = 1; i < n; i++) {
        if((pi[i - 1] == m and i >= 2 * m) or i == m){
            rta++;
            j = 0;
        }

        while (j > 0 and s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }

    if(pi[n - 1] == m) rta++;

    return rta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, z, w;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> z >> w;
        cin >> s;
        
        if(z == 1) cout << n << '\n';
        else{
            int l = 0, r = n / z + 1, m;
            while(l < r){
                m = (l + r + 1) / 2;
                if(kmp(s, m) >= z) l = m;
                else r = m - 1;
            }
            cout << r << '\n';
        }    
    }
    
    return 0;
}