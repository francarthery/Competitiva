#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int(x.size()))
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x <<" = "; for(auto e  : x ) cout<<e<< ' ';}cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int P = 1777771, MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};

struct Hash{
    vector<int> h[2], pi[2];
    vector<ll> vp[2];
    Hash(string& s){
        forn(k, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1), vp[k].resize(s.size() + 1);
        forn(k, 2){
            h[k][0] = 0;
            vp[k][0] = pi[k][0] = 1;
            ll p = 1;
            forr(i, 1, sz(s) + 1){
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1ll * pi[k][i - 1] * PI[k]) % MOD[k];
                vp[k][i] = p = (p * P) % MOD[k];
            }
        }
    }
    ll get(int s, int e){
        ll H[2];
        forn(i, 2){
            H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
            H[i] = (1ll * H[i] * pi[i][s]) % MOD[i];
        }
        return (H[0] << 32) | H[1];
    }
};

const int MAXN = 1e5 + 5;

int d1[MAXN], d2[MAXN];

void manacher(string & s){
    int l = 0, r = -1, n = sz(s);
    forn(i, n){
        int k = i > r ? 1 : min(d1[l + r - i], r - i);
        while(i + k < n and i - k >= 0 and s[i + k] == s[i - k]) k++;
        d1[i] = k--;
        if(i + k > r) l = i - k, r = i + k;
    }
    l = 0, r = -1;
    forn(i, n){
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1)) + 1;
        while(i + k <= n and i - k >= 0 and s[i + k - 1] == s[i - k]) k++;
        d2[i] = --k;
        if(i + k - 1 > r) l = i - k, r = i + k - 1;
    }
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out","w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;

    manacher(s);
    Hash h(s);
    vector<int> pf(n+1);
    forr(i,1,n+1){
        pf[i] = s[i-1] - 'a' + 1;
        pf[i] += pf[i-1];
    }
    // vdbg(pf);
    // vdbg(d1);
    // vdbg(d2);

    map<ll,int> bol;

    forn(i,n){
        
        // capicua largo IMPAR
        // aaacaaa => largo min = 0, largo max = n
        int l = -1, r = d1[i];
        while(r-l>1){
            int m = (l+r)/2;
            assert(i+m <= n);
            assert(i-m >= 0);
            ll hasheo = h.get(i-m, i+m+1);
            if(bol.count(hasheo)) // este capi ya ta
                l=m;
            else 
                r=m;    // r guarda el minimo largo que no tengo
        }

        for(int largo = r; largo < d1[i]; largo++){
            assert(i+largo <= n);
            assert(i-largo >= 0);
            // cout<<i ws i-largo ws i+largo;nl;
            // cout<<s.substr(i-largo, largo*2+1);nl;
            ll hasheo = h.get(i-largo, i+largo+1);
            // dbg(hasheo);
            bol[hasheo] = pf[i+largo+1] - pf[i-largo];
            // dbg((bol[hasheo]));
        }


        // capicua largo PAR
        // acca => largo min = 1, largo max = n
        //   i  => [i - largo, i + largo)
        l = 0, r = d2[i]+1;
        while(r-l > 1){
            int m = (r+l)/2;
            assert(i+m <= n);
            assert(i-m >= 0);
            ll hasheo = h.get(i-m, i+m);
            if(bol.count(hasheo))
                l = m;
            else 
                r = m;
        }

        // dbg(r);
        // dbg(d2[i]);
        for(int largo = r; largo <= d2[i]; largo++){
            assert(i+largo <= n);
            assert(i-largo >= 0);
// dbg(largo);
            ll hasheo = h.get(i-largo, i+largo);
            // cout<<i ws s[i] ws i-largo ws i+largo;nl;
            bol[hasheo] = pf[i+largo] - pf[i-largo];            
        }

    }

    ll ans = 0;
    for(auto [h, sum] : bol){
        ans += sum;
    }

    cout<<ans<<endl;


    return 0;
} 
