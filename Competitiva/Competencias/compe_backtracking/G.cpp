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
    cout << '[';
    for(auto c : v) cout << c << ',';
    cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

long long n, mi, larn;

void f(long long m, int sietes, int cuatros, int largo){
    if(largo > 14 or cuatros > 6 or sietes > 6) return;
    if(m != 0 and sietes == cuatros){
        if(m >= n){
            mi = min(mi, m);
            return;
        }
    }

    f(m * 10 + 4, sietes, cuatros + 1, largo + 1);
    f(m * 10 + 7, sietes + 1, cuatros, largo + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif
    mi = LLONG_MAX;
    long long m = 0;
    cin >> n;
    
    f(m, 0ll, 0ll, 0ll);
    cout << mi << '\n';
    
    return 0;
}