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
    #ifdef patente
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        string s, rta;
        cin >> s;
        int tam = sz(s), cont = 0;

        forr(i, 1, tam){
                if(s[i - 1] == 'a' and s[i] == 'b') cont++;
                else if(s[i - 1] == 'b' and s[i] == 'a') cont--;
        }
        if(cont == 0) rta = s;
        else{
            cont = 0;
            forn(i, tam){
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
                
                forr(i, 1, tam){
                    if(s[i - 1] == 'a' and s[i] == 'b') cont++;
                    else if(s[i - 1] == 'b' and s[i] == 'a') cont--;
                }

                if(cont == 0) {
                    rta = s;
                    break;
                }

                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }    
        cout << rta << '\n';    
    }
    
    return 0;
}