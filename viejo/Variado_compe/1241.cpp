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

    string pal1, pal2;
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        cin >> pal1 >> pal2;
        bool flag = false;
        if(pal2.size() <= pal1.size()){
            flag = true;
            forn(i, pal2.size()){
                if(pal1[pal1.size() - i - 1] != pal2[pal2.size() - i - 1]){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "encaixa" : "nao encaixa") << '\n';
    }
    
    return 0;
}