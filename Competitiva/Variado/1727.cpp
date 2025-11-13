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

typedef pair<int, int> ii;
int n, g, x, y;
vector<pair<int, int>> faltan;
vector<int> ma, mi;

void f(vector<pair<int, int>> &faltan, vector<int> &punt){
    if(faltan.empty()) {
        vector<pair<int, int>> puestos;
        forn(i, n) puestos.pb({punt[i], i});
        sort(all(puestos));
        int ant = -1, pos;

        forn(i, n){
            if(puestos[i].fr != ant){
                pos = i;
                ant = puestos[i].fr;
            }
            mi[puestos[i].sc] = max(mi[puestos[i].sc], n - pos);
        }
        ant = -1;
        for(int i = n - 1; i >= 0; i--){
            if(puestos[i].fr != ant){
                pos = i;
                ant = puestos[i].fr;
            }
            ma[puestos[i].sc] = min(ma[puestos[i].sc], n - pos);
        }
        return;
    }

    pair<int, int> ult = faltan.back();
    faltan.pop_back();
    punt[ult.fr] += 3;
    f(faltan, punt);
    punt[ult.fr] -= 3;
    punt[ult.sc] += 3;
    f(faltan, punt);
    punt[ult.fr]++;
    punt[ult.sc] -= 2;
    f(faltan, punt);
    punt[ult.fr]--;
    punt[ult.sc]--;
    faltan.pb(ult);
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int cont = 1, ind1, ind2;
    string pal1, pal2;
    while(cin >> n, n){
        vector<string> v(n);
        vector<int> punt(n);
        ma.assign(n, INT_MAX);
        mi.assign(n, 0);
        unordered_map<string, int> s;
        faltan.clear();

        forn(i, n) {
            cin >> pal1;
            s[pal1] = i;
            v[i] = pal1;
        }
        cin >> g;
        vector<vector<int>> m(n, vector<int>(n));
        forn(i, g){
            cin >> pal1 >> pal2 >> x >> y;
            ind1 = s[pal1];
            ind2 = s[pal2];
            m[ind1][ind2]++;
            m[ind2][ind1]++;

            if(x > y) punt[ind1] += 3;
            else if(x < y) punt[ind2] += 3;
            else{
                punt[ind1]++;
                punt[ind2]++;
            }
        }

        forn(i, n) forn(j, i){
            if(m[i][j] < 2) faltan.pb({i, j});
            if(m[i][j] < 1) faltan.pb({i, j});
        }

        f(faltan, punt);

        cout << "Group #" << cont++ << '\n';
        forn(i, n){
            cout << v[i] << ' ' << ma[i] << '-' << mi[i] << '\n';
        }
        cout << '\n';

    }
    
    return 0;
}
