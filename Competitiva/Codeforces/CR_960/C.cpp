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

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll ma = 0, sum = 0, x;
        
        vector<int> v(n);
        forn(i, n){
            cin >> x;
            sum += x;
            v[i] = x;
        }
        forn(j, 2){
            unordered_set<int> s;
            ma = 0;
            forn(i, n){
                if(s.count(v[i])) ma = max((int)ma, v[i]);
                else s.insert(v[i]);
                v[i] = ma;
                if(!j) sum += ma;
            }
        }

        ll ant = v[0], tam = 1;
        v.pb(-1);

        forr(i, 1, n + 1) {
            if(v[i] == ant) tam++;
            else if(v[i] != ant){
                if(tam > 1) sum += ant * tam * (n - i);
                sum += (((tam + 1) * tam) / 2) * ant;
                tam = 1;
            }
            ant = v[i];
        }

        cout << sum << '\n';
    }
    
    return 0;
}