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
        //freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    double sum = 0;
    string s;
    map<int, int> m;

    forn(i, n){
        cin >> s;
        double val = stod(s);
        int aux = s.back() - '0';
        if(aux == 5 or aux == 0) sum += val;
        else if(aux == 1 or aux == 6) sum += val - 0.01;
        else if(aux == 2 or aux == 7) sum += val - 0.02;
        else {
            m[aux % 5]++;   
            sum += val;
        }
    }

    int aux = min(m[3], m[4]);
    m[3] -= aux;
    m[4] -= aux;
    sum -= 0.02 * aux;

    sum -= (m[3] / 2) * 0.01;
    sum -= (m[4] / 2) * 0.01;

    cout << fixed << setprecision(2) << sum << '\n';

    
    return 0;
}