#include <bits/stdc++.h>
#define forr(i, a, n) for(long long i = a; i < n; i++)
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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
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

    ll x, aux, cont = 0;
    vector<int> v;
    cin >> x;
    forr(i, 1, x){
        aux = i * i;
        if(aux - x > 0){
            long double root = sqrtl(aux - x);
            if(root == floor(root)) {
                cont++;
                v.pb(i);
            }
        }
    }

    cout << cont << '\n';
    if(!v.empty()) for(int &i : v) cout << i << (i == v.back() ? '\n' : ' ');
    
    
    return 0;
}