#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl

using namespace std;

int l, o, s, t, tot=0;

void f(int a, int b, int c, int d){
    int mi = (int)1e9;
    if(a) mi = min(mi, l / a);
    if(b) mi = min(mi, o / b);
    if(c) mi = min(mi, s / c);
    if(d) mi = min(mi, t / d);

    tot += mi;
    l -= mi * a;
    o -= mi * b;
    s -= mi * c;
    t -= mi * d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    //bool flag
    cin >> l >> o >> s >> t;
    f(0, 4, 0, 0); //2
    f(2, 2, 0, 0); //6
    f(0, 0, 0, 4); //3
    f(1, 0, 1, 2); //5
    f(2, 0, 2, 0); //4
    f(4, 0, 0, 0); //1
    

    cout << tot << '\n';

    return 0;
}