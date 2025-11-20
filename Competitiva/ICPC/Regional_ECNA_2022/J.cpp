#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int tam = 52;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector<string> v(tam);
    forn(i, tam) cin >> v[i];

    vector<string> mazo;
    int ind = 0;
    while(1){
        mazo.pb(v[ind++]);
        bool flag = true;
        while(flag){
            flag = false;
            int ind2 = -1, ind1 = -1;
            for(int i = sz(mazo) - 1; i >= 3; i--){
                if(mazo[i][0] == mazo[i - 3][0]){
                    ind2 = i;
                    break;
                }
                else if(mazo[i][1] == mazo[i - 3][1] and ind1 == -1) ind1 = i;
            }

            if(ind2 != -1){
                mazo.erase(mazo.begin() + ind2 - 3, mazo.begin() + ind2 + 1);
                flag = true;
            }
            else if(ind1 != -1){
                mazo.erase(mazo.begin() + ind1 - 3);
                mazo.erase(mazo.begin() + ind1 - 1);
                flag = true;
            }
        } 
        if(ind == tam) break;   
    }

    cout << sz(mazo) << ' ';
    for(string s : mazo) cout << s << ' ';
    cout << '\n';

    return 0;
}