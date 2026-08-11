#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int(x.begin()))
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {for(auto e : x) cout<<e<<' '; cout<<endl;}

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;

bool alpha(char c) {
    return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') 
    or (c >= '0' and c <= '9'); 
}

int main(){
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t; cin >> t;
    cin.ignore();

    bool ok = true;
    set<char> validos{'!','?','.',',',';','$','#','^','{','}','_','=','+','*', ' '};
    set<char> pepo{'!','?','.',',',';','$','#','=','+','*'};

    auto check2 = [&](string &s) {
        int etapa = 0; // 0 alphanum, 1 _ o ^, 2 llave abre, 3 numero, 4, llavecierra;
        forn(i, s.size()){
            if(etapa == 0 and s[i] == '_' or s[i] == '^') etapa++;
            else if(etapa == 0 and alpha(s[i])) continue; //perdon
            else if(etapa == 1 and s[i] == '{') etapa++;
            else if(etapa == 2 and isdigit(s[i])) etapa++;
            else if(etapa == 3 and s[i] == '}') etapa++;
            else if(etapa == 3 and isdigit(s[i])) continue;
            else return false;
        }
        return etapa == 4;
    };

    auto check = [&](string &s) {
        bool alldig = true;
        for(char c : s) {
            if(c < '0' or c > '9') alldig = false;
            if(!alpha(c) and !validos.count(c)) return false;
            if(c == '^' or c == '_' or c == '{' or c == '}') return check2(s);
        }
        forn(i, s.size() - 1) {
            if(isdigit(s[i]) and pepo.count(s[i+1]) or isdigit(s[i+1]) and pepo.count(s[i])) return false;
        }
        if(alldig and s[0] == '0' and s.size() > 1) return false;
        else return true;
    };

    while(t--) {
        string s, pal; getline(cin, s);
        int n = s.size();
        stringstream sstream(s);
        
        if(s[0] == ' ' or s.back() == ' ') ok = false;
        forn(i, n-1) if(s[i] == ' ' and s[i+1] == ' ') ok = false;
        while(sstream >> pal) ok &= check(pal);
    }

    cout << (ok ? "Ok": "Validation failed") << '\n';

    return 0;
}
