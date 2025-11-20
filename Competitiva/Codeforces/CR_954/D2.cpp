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

int rta = INT_MAX;

void f(vector<int> &v, int res){
    if(res > 500) return;
    if(v.empty()) {
        rta = min(rta, res);
        return;
    }
    int ult = v.back();
    v.pop_back();
    f(v, res * ult);
    f(v, res + ult);
    v.pb(ult); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n;
        bool ceros = false;
        string pal;
        rta = INT_MAX;
        cin >> n >> pal;
        forn(i, n) if(pal[i] == '0') ceros = true;
        if(ceros and n > 3){
            cout << 0 << '\n';
            continue;
        }

        forr(i, 1, n){
            vector<int> num;
            forr(j, 0, n){
                if(j == i) num.pb((pal[i - 1] - '0') * 10 + (pal[i] - '0'));
                else if(i != j + 1) num.pb(pal[j] - '0');
            }
            int ult = num.back();
            //vdbg(num);
            num.pop_back();
            f(num, ult);
        }

        cout << rta << '\n';
    }
    
    return 0;
}