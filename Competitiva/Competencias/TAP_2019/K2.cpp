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
typedef pair<int, tuple<bool, char, int, int>> ibc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, a, b, rta = 0;
    char c;
    cin >> n;
    multiset<pair<int, int>> sd, sj;
    vector<ibc> ev; //((tiempo_evento, true si abre), persona)
    forn(i, n){
        cin >> c >> a >> b;
        ev.pb({a, {true, c, i, b}});
        ev.pb({b, {false, c, i, a}});
    }
    sort(all(ev), [](ibc &a, ibc &b){return a.fr < b.fr;});

    for(auto i : ev){
        if(get<0>(i.sc)){
            if(get<1>(i.sc) == 'D') sd.insert({i.fr, get<2>(i.sc)});
            else sj.insert({i.fr, get<2>(i.sc)});
        }
        else{
            if(get<1>(i.sc) == 'D'){
                if(!sj.empty()) rta = max(rta, i.fr - max(sj.begin() -> fr, get<3>(i.sc)));
                sd.erase({get<3>(i.sc), get<2>(i.sc)});
            }
            else{
                if(!sd.empty()) rta = max(rta, i.fr - max(sd.begin() -> fr, get<3>(i.sc)));
                sj.erase({get<3>(i.sc), get<2>(i.sc)});
            }
        }
    }

    cout << rta << '\n';
    
    return 0;
}