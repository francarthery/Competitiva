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
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    int ma = 1, sum = 0;
    cin >> s;
    for(char &c : s) ma *= c - '0';
    int tam = sz(s);
    forr(i, 1, tam){
        sum = 1;
        s[tam - i] = '9';
        s[tam - i - 1] -= 1;
        for(char &c: s) sum *= (c - '0');
        ma = max(ma, sum);
    }
    if(s[0] = '0') ma = max(ma, (int)pow(9, sz(s) - 1));
    cout << ma << '\n';
    
    return 0;
}