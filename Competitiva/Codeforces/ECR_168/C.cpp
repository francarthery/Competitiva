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
    cin >> t;
    while(t--){
        vector<int> ab{0};
        string s;
        int n, tot = 0;
        cin >> n >> s;
        forr(i, 1, n){
            if(s[i] == '(') ab.pb(i);
            else if(s[i] == '_'){
                if(!ab.empty()){
                    tot += i - ab.back() + 1;
                    if(i == ab.back() + 1) tot--;
                    ab.pop_back();
                }
                else{
                    ab.pb(i);
                }
            }
            else if(s[i] == ')'){
                tot += i - ab.back();
                ab.pop_back();
            }
        }

        cout << tot << '\n';
    }
    
    return 0;
}