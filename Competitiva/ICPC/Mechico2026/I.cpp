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
    set<char> pepe{'!','?','.',',',';','$','#','^','{','}','_','=','+','*', ' '};
    set<char> pepo{'!','?','.',',',';','$','#','=','+','*'};

    bool numant = false, noalpha = false, ceros = false, llaves = false, esnumero = false;

    while(t--) {
        string s; getline(cin, s);
        int n = s.size();
        // cout << s << '\n';

        forn(i, n) {
            if(!alpha(s[i]) and !pepe.count(s[i])) ok = false; // digito no valido
            if(s[0] == ' ' or s.back() == ' ') ok = false; //espacios iniciales o finales
            if(i and s[i-1] == ' ' and s[i] == ' ') ok = false; //dos espacios
            if(i == 0 and numant and !isdigit(s[i])) ok = false; //si termina en dig, empieza en dig siguiente
            if(i == 0) numant = false;

            // dbg(ceros); dbg(esnumero);
            
            if(s[i] == '}') {
                if(!llaves or !esnumero or esnumero and ceros) ok = false; //no numero en parentesis o llaves no balanceada
                llaves = false;
                esnumero = false;
                ceros = false;
            }
            
            if(isdigit(s[i])) {
                if((i and pepo.count(s[i-1])) or (i<n-1 and pepo.count(s[i+1]))) ok = false; //digito no seguido de 0s
                if(s[i] == '0' and !numant) ceros = true; //empieza en 0
                if(i == 0 or s[i-1] == ' ' or s[i-1] == '{') esnumero = true; //tengo un numero
            }
            else {
                esnumero = false;
                if(llaves) ok = false; //no hay numero entre llaves
            }
            
            
            // dbg(noalpha);
            if((s[i] == '^' or s[i] == '_') and (noalpha or (i and s[i-1] == ' '))) ok = false; //no alphanum antes de _ o ^
            
            if(s[i] == '{') {
                if(i == 0 or (s[i-1] != '^' and s[i-1] != '_')) ok = false; //sub o superindice invalido
                llaves = true;
                esnumero = false;
                ceros = false;
            }
            
            if(!alpha(s[i]) and s[i] != ' ') noalpha = true; //el string no es alphanumerico
            
            if(i == n-1 or s[i] == ' ') {
                if(esnumero and ceros) ok = false; //numero con ini/fin ceros                 
                if(llaves) ok = false;

                noalpha = false;
                ceros = false;
                esnumero = false;
            }

            numant = isdigit(s[i]);
            // cout << ok; dbg(ceros); dbg(numant);
        }
        // cout << '\n';
        if(llaves) ok = false;
    }
    // cout << ok;

    cout << (ok ? "Ok": "Validation failed") << '\n';


    return 0;
}
