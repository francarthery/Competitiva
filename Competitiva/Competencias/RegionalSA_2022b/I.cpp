#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define vdbg(x) cout<<#x<<": [";for(auto e:x)cout<<e<<", ";cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;

typedef pair<int,int> ii;
typedef  long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    string s; ll n; 
    cin >> s >> n;
    ll mi = 1e9 + 100;

    map<string, ll> dias{{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};
    vector<int> salto{0, 62, 61, 32, 31};

    ll hoy = dias[s];
    forn(i, n){
        ll p; cin >> p;

        if(!p){
            if(hoy == 3) mi = min(32ll, mi);
            else if(hoy == 4) mi = min(31ll, mi);
            else mi = min(30ll, mi);
            continue;
        }

        ll ini = (((hoy-p) % 7) + 7) % 7;

        if(ini != 0 and salto[ini] <= p){ //Si no es lunes
            p -= salto[ini];
        }
        
        p -= (p / 91) * 91;
        //dbg(p);
        
        while(p > 0){
            p -= 30;
            if(((hoy - p) % 7 + 7) % 7 == 5) p -= 2;
            else if(((hoy - p) % 7 + 7) % 7 == 6) p -= 1;
        }
        

        mi = min(mi, -p);
    }

    cout << mi << '\n';

    return 0;
}