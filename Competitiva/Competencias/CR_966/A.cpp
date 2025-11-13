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

    int t;
    bool flag = false;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> s;
        n = stoi(s);
        flag = true;
        if(s.size() < 3) flag = false;
        if(flag){
            flag = false;
            if(s[0] == '1' and s[1] == '0' and s[2] != '0' and n % (int)pow(10, sz(s) - 2) >= 2)  flag = true;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}