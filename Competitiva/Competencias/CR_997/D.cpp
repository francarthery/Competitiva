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
typedef tuple<int, int, int> iii;

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
        int n; cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];

        ll rta = 0;
        forr(x, 1, 11){
            vector<int> dif(n);
            forn(i, n) if(v[i] <= x) dif[i] = -1;
            else dif[i] = 1;

            unordered_map<int, iii> mp; //frecuencia, ultima aparicion, cant intervalos sin x
            mp[0] = {1, -1, 0};
            ll sum = 0, ult = -1;
            forn(i, n){
                sum += dif[i];
                if(v[i] == x) ult = i;

                if(get<0>(mp[sum]) > 0){
                    if(get<1>(mp[sum]) < ult) { //tengo x en el ultimo
                        rta += (get<0>(mp[sum]));
                        (get<2>(mp[sum])) = 0;
                    }
                    else{
                        rta += (get<0>(mp[sum]) - 1 - get<2>(mp[sum]));
                        get<2>(mp[sum])++;
                    }
                }
                get<0>(mp[sum])++;
                get<1>(mp[sum]) = i;
            }
        }

        cout << ((ll)(n) * (n + 1)) / 2 - rta << '\n';
    }


    
    return 0;
}