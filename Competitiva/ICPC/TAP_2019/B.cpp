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

double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, r, x, y;
    bool flag = true;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    forn(i, n){
        cin >> x >> y >> r;
        v[i]={r, {x, y}};
    }
    
    forn(i, n) forn(j, n){
        double d = dist(v[i].sc.fr, v[i].sc.sc, v[j].sc.fr, v[j].sc.sc);

        if(flag and i != j and d <= (v[i].fr + v[j].fr) and (min(v[i].fr, v[j].fr) + d) >= max(v[i].fr, v[j].fr)){
            //cout << dist(v[i].sc.fr, v[i].sc.sc, v[j].sc.fr, v[j].sc.sc) << '\n';
            flag = false;
            break;
        }
    }

    cout << (flag ? "SI" : "NO");

    return 0;
}