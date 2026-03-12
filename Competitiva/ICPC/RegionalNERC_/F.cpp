#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(stru) (int(stru.size()))
#define all(stru) stru.begin(), stru.end()
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define ws <<" "<<
#define nl cout<<"\n";
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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        forn(i,n){
            string s;cin>>s;
            if(s.find("xxx")!=s.npos) v[i] = 2;
            else {
                if(s.find("xx.")!=s.npos||s.find(".xx")!=s.npos) v[i] = 1;
            }
        }
        int xor_sum = 0;
        forn(i, n){ 
            xor_sum^= v[i];
        }

        if(xor_sum) cout << "Monocarp";
        else cout << "Polycarp";
        cout << '\n';
    }

    return 0;
}