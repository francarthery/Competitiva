#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";

using namespace std;

int main(){
    long double a, b, c; cin >> a >> b >> c;

    long long ans = (long long) ceil((a * b)/12);
    

    cout << ans * c << '\n';
    return 0;
}