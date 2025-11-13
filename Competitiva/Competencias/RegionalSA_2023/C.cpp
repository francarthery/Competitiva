#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int a = 31, b = 1e9 + 7;
vector<ll> p, h;

void Hash(vector<int> &s){
    p.resize(s.size());
    h.resize(s.size());

    p[0] = 1;
    h[0] = s[0];
    for(int i = 1; i < s.size(); i++) {
        h[i] = (h[i - 1] * a + s[i]) % b;
        p[i] = (p[i - 1] * a) % b;
    }
}

ll gethash(int l, int r){
    if(l == 0) return h[r];
    else return ((h[r] - h[l - 1] * p[r - l + 1]) % b + b) % b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    forn(i, n) cin >> v[i];


    if(k <= sqrtl(n)) {    
        vector<int> ps(k);
        int cont = 0;
        unordered_map<ll, int> m; 
        int ans = 0;

        Hash(ps);
        ll aux = gethash(0, k - 1);
        m[aux] = -1;

        forn(i, n) {
            if(!ps[v[i] - 1]) cont++;
            ps[v[i] - 1]++;
            if(cont == k) {
                forn(j, k) {
                    if(ps[j] == 1) cont--;
                    ps[j]--;
                }
            }
            Hash(ps);
            ll aux = gethash(0, k - 1);
            if(!m.count(aux)) m[aux] = i;
            else ans = max(ans, i - m[aux]);
        }
        cout << ans;        
    } else {
        int ans = 0;
        for(int i = k; i <= n; i += k) {
            vector<int> freq(k + 1);
            int cant = 0; // cont = cantidad de cara dist. cant = cant > i / k.

            forn(j, i) {
                if(freq[v[j]] == i / k) cant++;
                freq[v[j]]++;
            }
            
            if(cant) {
                forr(j, i, n) {
                    if(!cant) break;
                    freq[v[j - i]]--;
                    if(freq[v[j - i]] == i / k) cant--;
                    
                    if(freq[v[j]] == i / k) cant++;
                    freq[v[j]]++;
                }
            }

            if(!cant) ans = max(ans, i);
        }
       
        cout << ans;  
    }

    return 0;
}