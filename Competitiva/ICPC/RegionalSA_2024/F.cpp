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

    int n, k;
    cin >> k >> n;

    string ans, s3 = "-X-", s2 = "X-";
    if(k > (n + 1) / 2 or k < (n + 2) / 3) cout << "*\n";
    else{
        int len = n, puestos = 0;
        while(len >= 3 and (len - 2) / 2 >= k - puestos - 1) {
            ans += s3;
            puestos++;
            len -= 3;
        }
        while(len >= 2) {
            ans += s2;
            puestos++;
            len -= 2;
        }
        if(len){
            if(puestos == k) ans += '-';
            else ans += 'X';
        }

        cout << ans << '\n';
    } 

    
    return 0;
}