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
    cout << '[';
    for(auto c : v) cout << c << ',';
    cout << "\b]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

string penales;


void solve(int pos, int penal1, int penal2, int gol1, int gol2, int mi){
    if(pos > 9) return;
    if(penal1 + gol1 < gol2){
        mi = min(pos, mi);
        return;
    }else if(penal2 + gol2 < gol1){
        mi = min(pos, mi);
        return;
    }

    if(pos % 2 == 0){
        if(penales[pos] == '1'){
            gol1++;
            penal1--;
        }else if(penales[pos] == '0'){
            penal1--;
        }else{
            solve(pos+1, gol1+1, gol2, penal1-1, penal2, mi);
            solve(pos+1, gol1, gol2, penal1-1, penal2, mi);
        }
    }else{
        if(penales[pos] == '1'){
            gol2++;
            penal2--;
        }else if(penales[pos] == '0'){
            penal2--;
        }else{
			solve(pos+1, gol1, gol2+1, penal1, penal2-1, mi);
			solve(pos+1, gol1, gol2, penal1, penal2-1, mi);
        }
    }
    solve(pos+1, gol1, gol2, penal1, penal2, mi);
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif
    int t;

    cin >> t;

    while(t--){
		int penal1 = 5, penal2 = 5;
		int gol1 = 0, gol2 = 0;
		int mi = INT_MAX;

        cin >> penales;

        solve(0, 5, 5, 0, 0, INT_MAX);

        cout << mi << '\n';
    }

    
    return 0;
}
