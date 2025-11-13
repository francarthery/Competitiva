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

const int K = 20; //log2(cant_elementos) + 1
const int MAXN = 1e5;
vector<vector<int>> st(K, vector<int>(MAXN));

void sparse(vector<int> &v){ //Llamar a sparse antes para precomputar la tabla O(nlogn)
    st[0] = v;

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= v.size(); j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); //Construccion de abajo para arriba
}

int query(int l, int r){ //O(1)
    int i = (int)log2(r - l + 1);
    return max(st[i][l], st[i][r - (1 << i) + 1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    sparse(v);
    cout << query(1, 2) << '\n';
    cout << query(1, 8) << '\n';
    cout << query(4, 7) << '\n';
    cout << query(0, 9) << '\n';

    
    return 0;
}