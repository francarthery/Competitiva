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
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, g;
    string pal, q;
    cin >> n;
    vector<string> v(n);
    forn(i, n) cin >> v[i];
    pal = v[0];
    unordered_set<char> let;
    for(char &c : pal) let.insert(c); // letras de guess

    cin >> g;
    forn(i, g){
        cin >> q;
        int cont = 0;
        forn(j, n){ // recorro todas las palabras
            bool flag = true;
            forn(k, 5){
                if(q[k] == 'X' and let.count(v[j][k])) flag = false;
                else if(q[k] == '!' and (let.count(v[j][k]) == 0 or let.count(v[j][k]) and v[j][k] == pal[k])) flag = false;
                else if(q[k] == '*' and v[j][k] != pal[k]) flag = false;
                if(!flag) break;
            }
            if(flag) cont++;
        }   
        cout << cont << '\n';
    }
    
    return 0;
}