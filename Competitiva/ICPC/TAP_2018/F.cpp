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

    int n, m;

    cin >> n >> m;

    set<int> s;
    map<int, int> mapita;
    int e, faltan = m;

    forn(i, n){
        cin >> e;
        s.insert(e);
        mapita[e]++;
    }
    int tam = s.size();
    if(tam == 1) cout << "1\n";
    else if(tam == m) cout << "0\n";
    else if(tam == 2){
        int cont = 0;
        int aux;
        for(auto it = mapita.begin(); it != mapita.end(); it++){
            if(it -> second > 1){
                cont++;
                aux = it -> second;
            }
        }
        if(cont == 0) cout << m-2 << '\n';
        else if(cont == 1 and aux > 1) cout << m-1 << '\n';
        else cout << m << '\n';
    }else if(tam == 3){
        int cont = 0;
        for(auto it = mapita.begin(); it != mapita.end(); it++){
            if(it -> second > 1)cont++;
        }
        if(cont == 0 and m - tam == 1) cout << m-1 << '\n';
        else cout << m << '\n'; 
    }else cout << m << '\n';
    
    return 0;
}