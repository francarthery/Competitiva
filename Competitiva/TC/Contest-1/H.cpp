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
    int cont = 0;
    cin >> s;
    for(char &c : s){
        if(cont == 0 and c == 'h') cont++;
        else if(cont == 1 and c == 'e') cont++;
        else if(cont == 2 and c == 'l') cont++;
        else if(cont == 3 and c == 'l') cont++;
        else if(cont == 4 and c == 'o'){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
    return 0;
}