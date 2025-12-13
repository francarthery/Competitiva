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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
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

    int n, m, a, c, pares;
    while(cin >> n >> m and (n or m)){
        bool flag = false;
        cin >> a >> c;
        vector<int> v(c);
        forn(i, c) cin >> v[i];
        sort(all(v));

        int l = 0, r = c - 1, rta1 = 0, rta2 = 0, aramando = 0, raul = 0;
        
        if(m * 100 % a == 0){
            pares = (m * 100) / a;
            while(pares > rta1 and l <= r){
                if(v[r] > n) r--;
                else if(v[r] == n){
                    r--;
                    rta1++; raul++;
                }
                else if(v[r] + v[l] == n){
                    r--;
                    l++;
                    rta1++; raul += 2;
                }
                else if(v[r] + v[l] > n) r--;
                else if(v[r] + v[l] < n) l++;
            }
        }

        if(n * 100 % a == 0){
            l = 0;
            r = c - 1;
            pares = (n * 100) / a;
            while(pares > rta2 and l <= r){
                if(v[r] > m) r--;
                else if(v[r] == m){
                    r--;
                    rta2++; aramando++;
                }
                else if(v[r] + v[l] == m){
                    r--;
                    l++;
                    rta2++; aramando+=2;
                }
                else if(v[r] + v[l] > m) r--;
                else if(v[r] + v[l] < m) l++;
            }
        }

        if(rta1 != pares and rta2 != pares) cout << "impossivel\n";
        else cout << max(raul, aramando) << '\n';
    }
    
    
    return 0;
}