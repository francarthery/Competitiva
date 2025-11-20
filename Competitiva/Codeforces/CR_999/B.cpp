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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        map<int, int> m;
        forn(i, n) m[v[i]]++;

        int cont = 0, e1, e2, e3;
        bool flag = true;
        for(auto i : m){
            if(i.sc > 3){
                e1 = e2 = i.fr;
                cont = 2;
                break;
            }
            else if(i.sc > 1){
                cont++;
                if(cont == 1) e1 = i.fr;
                else if(cont == 2) e2 = i.fr;
                else break;
            }
        }

        if(cont == 0) flag = false;
        else if(cont == 1){
            m[e1] -= 2;
            if(m[e1] == 0) m.erase(e1);

            int ant = (*m.begin()).fr, mi = 1e9;
            for(auto it = ++m.begin(); it != m.end(); it++){
                if((*it).fr - ant < mi){
                    e2 = ant;
                    e3 = (*it).fr;
                    mi = (*it).fr - ant;
                }
                ant = (*it).fr;
            }
            if(sz(m) <= 1 or min(e2, e3) + 2 * e1 <= max(e2, e3)) flag = false;
        }

        if(flag){
            if(cont >= 2) cout << e1 << ' ' << e1 << ' ' << e2 << ' ' << e2 << '\n';
            else cout << e1 << ' ' << e1 << ' ' << e2 << ' ' << e3 << '\n';
        }
        else cout << -1 << '\n';

    }


    
    return 0;
}