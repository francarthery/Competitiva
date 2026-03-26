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
    vector<vector<int>> v(1e6, vector<int>(10));

    forn(i, 1e6) {
        int num = i;
        while(num >= 10) {
            int sum = 0;
            while(num) {
                sum += num % 10;
                v[i][num%10]++;
                num /= 10;
            }
            num = sum;
        }
        v[i][num]++;
    }


    while(t--) {
        string s; cin >> s;

        if(sz(s) == 1) {
            cout << s << '\n';
            continue;
        }

        int sum = 0;
        vector<int> frec(10);
        for(char c : s) {
            sum += c - '0';
            frec[c - '0']++;
        }

        auto f = [&](int x) {
            string ans;
            dfor(i, 10) ans += string(frec[i] - v[x][i], i + '0');
            while(x >= 10) {
                ans += to_string(x);
                int aux = 0;
                while(x) {
                    aux += x % 10;
                    x /= 10;
                }
                x = aux;
            }
            ans += x + '0';
            
            return ans;
        };

        forn(i, sum+1) {
            int sum2 = 0;
            forn(j, 10) {
                if(frec[j] < v[i][j]) {
                    sum2 = -1;
                    break;
                }
                sum2 += (frec[j] - v[i][j]) * j;
            }
            if(sum2 == i) {
                cout << f(i) << '\n';
                break;
            }
        }
    }



    return 0;
}