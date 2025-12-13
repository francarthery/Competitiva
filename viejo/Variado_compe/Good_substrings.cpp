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

vector<int> pi;

void kmp(string &s) {
    int n = (int)s.length();
    pi.resize(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s, val;
    unordered_set<ll> u;
    cin >> s >> val;
    int k, error = 0;
    cin >> k;
    
    Hash(s);
    
    forn(i, s.size()){
        error = 0;
        for(int j = i; j >= 0; j--){
            if(val[s[j] - 'a'] == '0') error++;
            if(error <= k) u.insert(gethash(j, i));
            else break;
        }
    }
    cout << u.size() << '\n';

    return 0;
}