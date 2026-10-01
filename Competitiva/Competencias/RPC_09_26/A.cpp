#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = ";for(auto  e : x) cout<<e<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef fran
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<string> v(n), res(n);
    forn(i, n) cin >> v[i];
    vector<int> frec(256);
    int shift = 0;
    forn(i, n) {
        for(char c : v[i]) {
            int car = c;
            car-='a';
            car = ((car - shift) % 26 + 26) % 26;
            car += 'a';
            res[i] += car;
            
            frec[car]++;
            if(frec[car] % k == 0) {
                shift++;
                frec[car] = 0;
            }
        }
    }

    forn(i, n) cout << res[i] << ' ';
    cout << '\n';

    return 0;
}