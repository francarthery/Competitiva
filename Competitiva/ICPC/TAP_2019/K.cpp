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
bool compare(pair<int , int> &a, pair<int , int> &b){
    return a.second - a.first  > b.second - b.first;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    vector<pair<int , int>> d,j;
    int t, res=0;
    char l;
    int s, e;
    cin >> t;

    while(t--){
        cin >> l >> s >> e;

        if(l=='D') d.push_back(make_pair(s,e));
        else j.push_back(make_pair(s,e));
    }
    sort(d.begin(), d.end(), compare);
    sort(j.begin(), j.end(), compare);
    forn(i, d.size()){
        int mayor=0;
        if(res < d[i].sc - d[i].fr ){
            forn(k, j.size()){
                if(max(d[i].fr , j[k].fr)  < min(d[i].sc , j[k].sc) and  min(d[i].sc , j[k].sc) - max(d[i].fr , j[k].fr) > mayor){
                    mayor = min(d[i].sc , j[k].sc) - max(d[i].fr , j[k].fr);
                }
            }
        }
        if(mayor > res) res = mayor;
    }
    cout << res << '\n';

    return 0;
}