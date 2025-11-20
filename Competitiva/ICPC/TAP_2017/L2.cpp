#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl

using namespace std;
int l, o, s, t, ind = 1, ma = 1, rta = 0;

int f(int a, int b, int c, int d){
    int mi = (int)1e9, tot = 0;
    if(a) mi = min(mi, l / a);
    if(b) mi = min(mi, o / b);
    if(c) mi = min(mi, s / c);
    if(d) mi = min(mi, t / d);

    tot += mi;
    l -= mi * a;
    o -= mi * b;
    s -= mi * c;
    t -= mi * d;

    return tot;
}

int fu(int in){
    int tot = 0;
    if(in == 3) tot += f(2, 0, 2, 0);
    else if(in == 2) tot += f(0, 0, 0, 4);
    else if(in == 4) tot += f(1, 0, 1, 2);
    else if(in == 0) tot += f(4, 0, 0, 0);
    else if(in == 5) tot += f(2, 2, 0, 0);
    else if(in == 1) tot += f(0, 4, 0, 0);
    return tot;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif
    
    int l1, o1, s1, t1;
    cin >> l1 >> o1 >> s1 >> t1;
    bool flag = true;

        ma = 0;
        vector<int> v{0,1,2,3,4,5};

    do{
        l = l1; o = o1; s = s1; t = t1;
        rta = max (rta, fu(v[0]) + fu(v[1]) + fu(v[2]) + fu(v[3]) + fu(v[4]) + fu(v[5]));
    }while(next_permutation(all(v)));
        
    //rta = fu(1) + fu(5) + fu(2) + fu(4) + fu(3) + fu(0);
    cout << rta << '\n';

    return 0;
}