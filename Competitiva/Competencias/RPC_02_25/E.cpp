#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

    long double n, k, p; cin >> n >> k >> p; 

    long double restart = 0.3 + n * 0.1;
    long double backspace = (0.1 + (n - k) * 0.1) + ((100 - p) * (restart + 0.1)) / 100;
    long double cont = (p * (restart + 0.1)) / 100 + ((n - k) * 0.1);

    if(cont < backspace and cont < restart) cout << "continue\n";
    else if(backspace < restart) cout << "backspace\n";
    else cout << "restart\n";


    return 0;
}