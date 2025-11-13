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
    char x;
    cin >> t;
    while(t--){
        cin >> n;
        ll rta = 0, contr = 0;
        vector<int> v(n), ps(n + 1), posl;
        vector<char> p(n);
        forn(i, n) cin >> v[i];
        forn(i, n){
            cin >> x;
            p[i] = x;
            if(x == 'L') contr++; //Guardo donde esta el siguiente l
        }
        reverse(all(posl));
        forn(i, n) ps[i + 1] = ps[i] + v[i]; //Prefix sum
        vector<int> st;
        forn(i, n){
            if(p[i] == 'L') {
                st.pb(i);
                posl.pop_back(); //Saco la ultima l
            }
            else{
                if(st.empty() or posl.back() - i > st.size()) continue;
                else{
                    rta += ps[i + 1] - ps[st.back()];
                    st.pop_back();
                }   
            }
        }
        cout << rta << '\n';
    }

    return 0;
}