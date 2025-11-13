#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< (x) << endl;
#define ws <<" "<<
#define nl cout << "\n";
#define vdbg(x) cout << "[ "; for(auto i : x) cout << i << ", ";cout << " ]"; nl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif


    set<ii> s;
    int a, b; cin >> a >> b;
    if((((a + b) * (a + b - 1)) / 2) % b == 0) cout << (((a + b) * (a + b - 1)) / 2) % b << '\n';
    else cout << (((a + b) * (a + b - 1)) / 2) << '\n';

    return 0;
}