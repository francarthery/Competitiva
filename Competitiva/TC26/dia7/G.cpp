#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;}
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef fran
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    for(char e : s) m[e]++;
    
    if(m.size() == 1) cout << m.begin() -> first;
    else if(m.size() == 3) cout << "BGR";
    else{
        vector<char> v;
        bool ok1 = false, ok2 = false, ok3 = false;
        for(auto [x, y] : m){
            if(x == 'B') ok1 = true;
            else if(x == 'R') ok3 = true;   
            else ok2 = true;
            if(y > 1) v.push_back(x);
        }
        if(v.size() == 2) cout << "BGR";
        else{
            if(v.size() == 0){
                if(!ok1) cout << "B";
                else if(!ok2) cout << "G";
                else cout << "R";
            }else{
                if(v[0] == 'R') cout << "BG";
                else if(v[0] == 'B') cout << "GR";
                else cout << "BR";
            }
        } 
    }
    return 0;
}