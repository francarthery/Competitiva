#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) (int(a.size()))
#define all(x) x.bagin(), x.end()
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define vdbg(x) cout<<#x<<": [";for(auto e:x)cout<<e<<", ";cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";

using namespace std;

typedef pair<int,int> ii;
typedef  long long ll;

int main(){

    int n; cin >> n;
    vector<string> v(n);
    map<int, int> frec;
    forn(i, n) {
        cin >> v[i];
        frec[v[i][0]]++;
    }

    forn(i, n){
        bool flag = true;
        map<int, int> m;
        for(char c : v[i]) m[c]++;
        for(auto j : m){
            if(frec[j.first] < 1) flag = false;
        }

        if(flag){
            cout << "Y\n";
            return 0;
        }
    }

    cout << "N\n";

    return 0;
}