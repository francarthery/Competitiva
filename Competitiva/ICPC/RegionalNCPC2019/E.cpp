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

    string s;
    getline(cin, s);
    //cin.ignore();
    int mov = 1;
    for(char c : s) if(c == ' ') mov++;

    int n; cin >> n;
    vector<string> pals(n); 
    forn(i, n) cin >> pals[i];

    vector<int> v(n), t1, t2;
    forn(i, n) v[i] = i;


    int pos = 0;
    bool team = 0;
    forn(i, n){
        pos = (pos + (mov - 1)) % sz(v);

        if(!team) t1.pb(v[pos]);
        else t2.pb(v[pos]);

        team = !team;
        v.erase(v.begin() + pos);
        if(pos == sz(v)) pos = 0;
    }

    //vdbg(t1); vdbg(t2);
    //reverse(all(t1));
    //reverse(all(t2));

    cout << sz(t1) << '\n';
    for(int i : t1) cout << pals[i] << '\n';
    
    cout << sz(t2) << '\n';
    for(int i : t2) cout << pals[i] << '\n';


    return 0;
}