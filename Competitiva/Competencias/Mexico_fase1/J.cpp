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
    cout.tie(0);
 
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
 
    int n; cin >> n;
    string s; cin >> s;
    vector<int> masks(1 << 26, -1);
    masks[0] = 0;
    
    /*
    Caso 1. Misma mascara: igual paridad en todos los bits
    Caso 2. Mascara variando un bit: igual paridad en todos - 1
    */
 
    int mask = 0, rta = 1;
    forn(i, n){
        mask ^= (1 << (s[i] - 'a'));
        int mi = n; //menor indice que alcance
    
        if(masks[mask] != -1){ //caso 1
            mi = min(mi, masks[mask]);
        }else masks[mask] = i + 1;
 
        forn(j, 26){
            int aux = mask;
            aux ^= (1 << j);
 
            if(masks[aux] != -1){ //caso 2
                mi = min(mi, masks[aux]);
            }
        }
 
        rta = max(rta, i - mi + 1);
    }
 
    cout << rta << '\n';
 
    return 0;
}