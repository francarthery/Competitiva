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

    long long d, v, mins, rh, rm;
    cin >> d >> v;
    long long h = (d * 60) / v;
    
    mins = (long long)h % 1440;

    if(mins < 300) rh = 19 + mins / 60;
    else rh = mins / 60 - 5;
    rm = mins % 60;

    cout << setfill('0') << setw(2) << rh << ':' << setw(2) << rm << '\n';
    
    return 0;
}