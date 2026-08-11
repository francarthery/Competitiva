#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define fore(i,s,n) forsn(i,s,n)
#define dforn(i,n) dforsn(i,0,n)
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

// The maximum length of the resulting
// convolution vector is 2^LG
const int LG = 23;
using ll = long long;

template<class u, class uu, u p, u root>
struct FFT {
	u r[1+(2<<LG)];
	constexpr u m(u a, u b) {
		uu k = uu(a)*b;
		#define op(g) g*(g*p+2)
		k += u(k) * (op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a) { return a-k*(a>=k); }
	FFT() {
		u k = r[2<<LG] = -p%p, b=root, e = p>>LG;
		for(; e; e/=2, b=m(b,b)) if(e%2) k=m(k, b);
		dforn(i, 2<<LG) r[i]=red(p, m(r[i+1], k)), i&(i-1)?0:k=m(k,k);
		assert(r[2] != r[3]); assert(r[1] == r[2]);
	}
	vector<ll> cv(const vector<ll> &as, const vector<ll> &bs, u *v) {
		int c=max(sz(as)+sz(bs)-1, 0), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		forn(i, n)
			v[i] = i<sz(as) ? u(as[i]) : 0,
			v[i+n] = i<sz(bs) ? u(bs[i]) : 0;
		for(auto s:{v,v+n})
		dforsn(j, 2, n+1) for(int k=j&-j; k/=2;) forsn(i, j-k, j)
			x=s[i], y=s[i-k],
			s[i-k] = red(2*p, x+y),
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		forn(i, n) v[i] = m(v[i], v[i+n]);
		forsn(j, 2, n+1) for(int k=1; !(k&j); k*=2) forsn(i, j-k, j)
			x = m(v[i], r[3*k+j-i]),
			y = red(2*p, v[i-k]),
			v[i-k]=x+y, v[i]=2*p+y-x;
		forn(i, c) v[i] = red(p, m(v[i], h));
		return vector<ll>(v, v+c);
	}
};

// For modular convolutions modulo 998244353:
vector<ll> conv_small(const vector<ll> &as, const vector<ll> &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft; //tambien puede ser 469762049
	return fft.cv(as, bs, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> g(n);
        int a, b;
        forn(i, n-1) {
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        int ma = 0, node = 0, n1, n2;
        function<void(int, int, int)> dfs1 = [&](int s, int f, int d) {
            if(d > ma) {
                ma = d;
                node = s;
            }
            for(int u : g[s]) if(u != f) dfs1(u, s, d+1);
        };

        function<bool(int, int, int)> dfs2 = [&](int s, int f, int d) -> bool {
            bool ans = false;
            if(d == ma) ans = true;
            for(int u : g[s]) if(u != f) {
                bool son = dfs2(u, s, d+1);
                if(d == ma/2 and son) n1 = s, n2 = u;
                ans |= son; 
            }
            return ans;
        };

        function<bool(int, int, int, vector<ll>&)> dfs3 = [&](int s, int f, int d, vector<ll> &v) -> bool {
            int ans = d == ma/2;
            for(int u : g[s]) if(u != f) {
                ans += dfs3(u, s, d+1, v);
            }
            if(sz(g[s]) > 2 and ans >= 2) v[d] = 1;
            return ans;
        };

        dfs1(0, -1, 0);
        int ext1 = node;
        ma = node = 0;
        dfs1(ext1, -1, 0);
        dfs2(node, -1, 0);

        vector<ll> va(n), vb(n);
        dfs3(n1, n2, 0, va);
        dfs3(n2, n1, 0, vb);

        va[ma/2] = 1; vb[ma/2] = 1;
        vector<ll> ans = conv_small(va, vb);
        ll cant = 0;
        forn(i, sz(ans)) if(ans[i]) cant++;
        cout << cant << ' ';
        forn(i, sz(ans)) if(ans[i]) cout << i+1 << ' ';
        cout << '\n';
    }




    return 0;
}