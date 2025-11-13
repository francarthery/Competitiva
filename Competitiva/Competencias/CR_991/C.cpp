#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) cout << '['; for(auto &i : x) cout << i << ", "; cout << "]\n";
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

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
        string s;
        cin >> s;
        ll cant2 = 0, cant3 = 0, sum = 0;
        for(char &c : s){
            sum += c - '0';
            if(c == '2') cant2++;
            else if(c == '3') cant3++;
        }

        int mod = sum % 9;
        bool flag = false;

        if(mod == 0) flag = true;
        else if(mod == 1){
            if(cant2 >= 4 or (cant3 >= 1 and cant2 >= 1)) flag = true;
        }
        else if(mod == 2){
            if(cant2 >= 8 or (cant3 >= 1 and cant2 >= 5) or (cant3 >= 2 and cant2 >= 2)) flag = true;
        }
        else if(mod == 3){
            if(cant3 >= 1 or cant2 >= 3) flag = true;
        }
        else if(mod == 4){
            if(cant2 >= 7 or (cant3 >= 1 and cant2 >= 4) or (cant3 >= 2 and cant2 >= 1)) flag = true;
        }
        else if(mod == 5){
            if(cant2 >= 2) flag = true;
        }
        else if(mod == 6){
            if(cant2 >= 6 or (cant3 >= 1 and cant2 >= 3) or (cant3 >= 2)) flag = true;
        }
        else if(mod == 7){
            if(cant2 >= 1) flag = true;
        }
        else if(mod == 8){
            if(cant2 >= 5 or (cant3 >= 1 and cant2 >= 2)) flag = true;
        }

        cout << (flag ? "YES" : "NO" ) << '\n';
    }


    
    return 0;
}