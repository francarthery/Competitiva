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

int val = 0, val2 = 0, falt = 0, rta = 0;

void f(){
    if(falt == 0){
        if(val2 == val) rta++;
        return;
    }

    --falt;
    val2++;
    f();
    val2-= 2;
    f();
    val2++;
    falt++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    string pal1, pal2;
    cin >> pal1 >> pal2;
    for(char c: pal1) 
        if(c == '+') val++;
        else val--;

    for(char c: pal2) 
        if(c == '+') val2++;
        else if(c == '-') val2--;
        else falt++;

    f();
    
    double cant = pow(2, falt);
    double ans = rta/cant;

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}