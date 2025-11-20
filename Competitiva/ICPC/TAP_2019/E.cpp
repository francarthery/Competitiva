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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    double n, m, x, y;
    double ma, ma1, ma2, mb, mb1, mb2;
    
    cin >> n >> m >> x >> y;

    ma1 = x*100 / n;
    ma2= y*100 / m;
    ma= (ma2 + ma1)/2;

    mb1 = x+y;
    mb2 = n+m;
    mb = mb1*100 / mb2;

    mb = floor(mb * 1000000000000);
    ma = floor(ma * 1000000000000);
    if(mb == ma) cout << "C\n";
    else if(mb > ma) cout << "B\n";
    else cout << "A\n"; 
    return 0;
}