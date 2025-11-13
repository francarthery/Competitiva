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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
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

    int n, s1, s2; 
    cin >> n >> s1 >> s2;
    
    vector<bool> v(n, true);
    vector<int> res;
    int elim = 0, pos1 = 0, pos2 = n - 1;
    s1--; s2--;
    while(elim < n - 2){
        int cont = 0;
        while(cont < s1){
            pos1 = (pos1 + 1) % n;
            if(v[pos1] == true) cont++;
        }
        cont = 0;
        while(cont < s2){
            pos2 = (pos2 - 1 + n) % n;
            if(v[pos2] == true) cont++;
        }

        if(pos1 == pos2) {
            res.pb(pos1 + 1);
            elim++;
        }
        else elim += 2;
        v[pos1] = v[pos2] = false;

        cout << pos1 + 1 << ' ' << pos2 + 1 << '\n';

        pos1 = (pos1 + 1) % n;
        while(v[pos1] == false) pos1 = (pos1 + 1) % n;
        pos2 = (pos2 - 1 + n) % n;
        while(v[pos2] == false) pos2 = (pos2 - 1 + n) % n;
    }

    forn(i, n) if(v[i] == true) res.pb(i + 1);
    sort(all(res));
    for(int &i : res) cout << i << ' ';
    cout << '\n';
    
    return 0;
}