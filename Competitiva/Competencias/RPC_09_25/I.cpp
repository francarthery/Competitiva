#include<bits/stdc++.h>

#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(a) ((int)(a.size()))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) <<endl;
#define vdbg(x) {cout <<"["; for(auto i:x){cout << i << ", "; cout << "]" <<endl; }}
#define ws <<' '<<
#define nl <<endl;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    vector<map<long double, long double>> v(3);

    forn(i, 3){
        forn(j, 6){
            long double x; cin >> x;
            v[i][x]++;
        }
    }

    forn(i, 3){
        long double p1 = 0, p2 = 0, e1 = 0, e2 = 0;
        bool ok = false;
        forn(j, 3){
            if(i == j) continue;
            for(auto it = v[i].begin(); it != v[i].end(); it++){
                long double prob = 0, e = 0;
                for(auto it2 = v[j].begin(); it2 != v[j].end(); it2++){
                    if(it -> first > it2 -> first) prob+= it2 -> second;
                    else if(it -> first == it2 -> first) e+= it -> second * it2 -> second;
                }
                
                if(!ok) p1+= prob * (it -> second), e1+= e;
                else p2+= prob * (it -> second), e2+= e;
            }
            if(!ok) ok = true;
        }
        
        if(p1 / (36.0 - e1) >= 0.5 and p2 / (36.0 - e2) >= 0.5){
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << "No dice\n";

    return 0;

}