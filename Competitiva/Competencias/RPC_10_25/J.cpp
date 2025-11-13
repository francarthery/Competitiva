#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";
typedef long long ll;

using namespace std;

int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
    #endif

    int n; cin >> n;
    set<string> dic;
    
    forr(i,0,n){
        string s; cin >> s ;
        dic.insert(s);
    }
    int m; cin >> m;
    while(m--){
        string s; cin >> s;
        if(dic.find(s) != dic.end()){
            cout << 1;nl;
            continue;
        }
        string aux;
        int f = 0;
        forr(i,0,sz(s)){
            aux+=s[i];
            if(dic.find(aux) != dic.end()){

                string x = s.substr(i+1);
                if(dic.find(x) != dic.end()){
                    cout << 2;nl;
                    f = 1;
                    break;
                }

            }
        }

        if(f) continue;
        cout << 0;nl;
    }   

    return 0;
}