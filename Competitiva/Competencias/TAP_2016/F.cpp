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
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n; 
    cin >> n;
    string x;
    
    vector<ll> v(3);
    ll cont = 0;
    forn(i, n){
        cin >> x;
        string aux = "#";
        for(auto e : x){
            if((aux == "#" or aux == "DR") and e == 'D') aux = "D";
            else if(aux == "D" and e == 'R'){ cont++; aux = "DR";}
            else if(aux == "#" and e == 'R') aux = "R";
            else if(aux == "R" and e == 'D') aux = "RD";
            else if(aux == "RD" and e == 'R'){ cont++; aux = "R";}
        }
        if(aux == "D") v[0]++;
        else if(aux == "R") v[1]++;
        else if(aux == "RD") v[2]++;
    }

    if(v[0] and v[1] and v[2]){ 
        cont+= v[2] + 1; 
        v[2] = 0;
        v[1]--;
        v[0]--;
    }
    if(v[0] and v[1]) cont+= min(v[0], v[1]);
    else if(v[0] and v[2]) cont+= v[2];
    else if(v[1] and v[2]) cont += v[2];
    else if(v[2]) cont+= v[2] - 1;
    
    cout << cont;
    return 0;
}