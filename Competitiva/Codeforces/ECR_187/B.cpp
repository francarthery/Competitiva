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
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
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

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<int, int> frec;
        int sum = 0;
        for(char c : s) {
            frec[-(c - '0')]++;
            sum += c - '0';
        }

        int rta = 0;
        for(auto i : frec) {
            if(sum < 10) break;
            forn(j, i.sc) {
                if(j < i.sc - 1) sum += i.fr;
                else if(j == i.sc - 1 and s[0] - '0' != -i.fr) sum += i.fr;
                else sum += (i.fr + 1);
                rta++;
                if(sum < 10) break;
            }
        }

        cout << rta << '\n';
    }


    return 0;
}