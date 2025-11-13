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

bool esPrimo(int N){
	if(N == 2) return true;
	if(N == 1 or N % 2 == 0) return false;
	for(int i = 3; i * i <= N; i++)
		if(N % i == 0) return false;
	
	return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    int t1, m, r1, r2;
    bool ok;

    cin >> t;
    while(t--){
     
        cin >> t1;
        ok = true;
        if(t1<5){
            cout << "-1\n";
        }
        else{
            if(t1%2==0){
                r1=t1/2-1;
                r2=t1/2+1;    
            }else{
                r1=t1/2;
                r2=t1/2+1;
            }

            while(ok and r1 > 0){
                if(!esPrimo(r1) and !esPrimo(r2)){
                    cout << r1 << ' ' << r2 << '\n';
                    break;
                }else{
                    r1--;
                    r2++;
                }
            }
        }
    }
    
    return 0;
}