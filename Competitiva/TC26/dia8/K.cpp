#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}



using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    string s; cin >> s;


    double ans = 0;
    auto f = [&](string &s) {
        // dbg(s);
        int fin = sz(s);
        int num = 0;
        if(sz(s) >= 3 and s[fin-3] == '.') {
            fin -= 2;
            ans += (double)stoi(s.substr(fin)) / 100;
        }
        // dbg(ans);

        forn(i, fin) {
            if(s[i] != '.'){
                num *= 10;
                num += s[i] - '0';
            }
        }

        ans += num;
    };

    string num;
    for(char c : s) {
        if(c >= 'a' and c <= 'z') {
            if(sz(num)) f(num);
            num.clear();
        }
        else num += c;
    }
    if(sz(num)) f(num);

    // dbg(ans);

    string res;
    ll numero = round(ans * 100);
    // dbg(numero);
    res += numero % 10 + '0';
    numero /= 10;
    res += numero % 10 + '0';
    numero /= 10;
    if(res == "00") res.clear();
    else res += '.';
    int cont = 0;
    // dbg(numero);
    if(sz(res) and !numero) res+= '0';
    while(numero) {
        res += numero % 10 + '0';
        numero /= 10;
        cont++;
        if(numero and cont % 3 == 0) res += '.';
    }
    reverse(all(res));
    cout << res << '\n';
        
    return 0;
}