#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, char> ic;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    long long n, m, k;
    long long ans = 1;
    char l;  
    cin >> n >> m >> k;
    vector<vector<ic>> v(n, vector<ic> (m));
    
    forn(i, n) forn(j, m){
        cin >> l;
        if(isdigit(l)) v[i][j] = {l - '0', 'd'};
        else v[i][j] = {k, 'n'};
    }

    forn(i, n){
        forn(j, m){
            if(i == 0 and i < n-1){
                if(v[i][j].sc == 'd'){
                    if(v[i+1][j].sc == 'd' and v[i+1][j].fr == v[i][j].fr){
                        cout << "0\n";
                        return 0;
                    }else if (v[i+1][j].sc == 'n')v[i+1][j].fr--;
                }else if (v[i+1][j].sc == 'n')v[i+1][j].fr--;
            }
            if(i == n-1 and i > 0){
                if(v[i][j].sc == 'd'){
                    if(v[i-1][j].sc == 'd' and v[i-1][j].fr == v[i][j].fr){
                        cout << "0\n";
                        return 0;
                    }else if (v[i-1][j].sc == 'n')v[i-1][j].fr--;
                }else if (v[i-1][j].sc == 'n')v[i-1][j].fr--;
            }
            if(j == 0){
                if(v[i][j].sc == 'd'){
                    if(v[i][j+1].sc == 'd' and v[i][j+1].fr == v[i][j].fr){
                        cout << "0\n";
                        return 0;
                    }else if (v[i][j+1].sc == 'n')v[i][j+1].fr--;
                }else if (v[i][j+1].sc == 'n')v[i][j+1].fr--;
            }
        }
    }

    forn(i, n){
        forn(j, m){
            if(v[i][j].sc == 'n') {
                ans*= v[i][j].fr;
                ans%= (int) 1e9 + 7;
            }
        }
    }
    cout << ans << '\n';
    
    
    
    return 0;
}