#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) for(auto &e: x) cout<<"[";for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;



using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s; cin >> s;
    int n = sz(s);
    int oct = 0;
    if(s[0] != ':') oct++;
    vector<string> v;
    string aux;
    char ant = '#';
    int pos = 0;
    forn(i, n) {
        if(s[i] != ':') aux += tolower(s[i]);
        else if(sz(aux)) {
            v.push_back(aux);
            aux = "";
        }

        if(ant == ':' and ant == s[i]) pos = sz(v);
        ant = s[i];
    }
    if(sz(aux)) v.push_back(aux);

    string ans;
    forn(i, sz(v)) {
        if(i == pos) {
            forn(j, 8 - sz(v)) ans += string(4, '0') + ':';
        }
        ans += string(4 - sz(v[i]), '0') + v[i] + ':';
    }
    if(pos == sz(v)) forn(j, 8 - sz(v)) ans += string(4, '0') + ':';

    ans.pop_back();

    cout << ans << '\n';

    return 0;
}