#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    int t; cin >> t;
    vector<char> disp;
    forn(i, 10) disp.push_back('0' + i);
    forn(i, 26) disp.push_back('a'+i);
    forn(i, 26) disp.push_back('A'+i);
    while(t--) {
        int r, c, k; cin >> r >> c >> k;
        vector<string> v(r);
        int arroz = 0;
        forn(i, r) {
            cin >> v[i];
            forn(j, c) if(v[i][j] == 'R') arroz++;
        }

        int ind = 0;
        int asigno = arroz / k;
        int sobra = arroz % k;
        
        forn(i, r) if(i % 2) reverse(all(v[i]));

        int need = asigno + (sobra > 0);
        sobra--;

        forn(i, r) forn(j, c) {
            char letra = disp[ind];
            if(v[i][j] == 'R' and arroz > 1) {
                need--;
                if(!need){ 
                    need = asigno + (sobra > 0);
                    sobra--;
                    ind++;
                }    
                arroz--;
            }
            v[i][j] = letra;
        }

        forn(i, r) if(i % 2) reverse(all(v[i]));
        forn(i, r) cout << v[i] << '\n';
    }

    
    return 0;
}