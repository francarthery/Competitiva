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
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        int pot = 1, ma = 0;
        while(pot < n){
            bool flag = true;
            vector<int> conj1, conj2;
            forn(i, n){
                if(flag) conj1.pb(i + 1);
                else conj2.pb(i + 1);
                if((i + 1) % pot == 0) flag = !flag;
            }
            
            cout << conj1.size() << ' ' << conj2.size() << ' ';
            for(int &i : conj1) cout << i << ' ';
            for(int &i : conj2) cout << i << ' ';
            cout << endl;

            cin >> x;
            ma = max(ma, x);
            pot *= 2;
        }

        cout << "-1 " << ma << endl;
    }
    
    return 0;
}