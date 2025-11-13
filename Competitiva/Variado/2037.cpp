#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> cad;
string res;

void lista(int j){
    char c; bool flag = true;
    
    while(!cad[j].empty()){
        c = cad[j][0]; //Primer caracter de la cadena
        cad[j].erase(0, 1); //eliminamos el primer caracter
    
        while(c - '0' == 1 and flag){ // Si es un 1 sumamos esa cadena
            res += char(j + '0');
            if(!cad[j].empty()){
                c = cad[j][0];
                cad[j].erase(0, 1);
            }
            else flag = false;
        }

        lista(c - '0');
    }
}

int main(){

    string x;
    while(cin >> n and n != -1){
        cad.assign(n + 1, "");
        res = "";

        for(int i = 2; i <= n; i++){
            cin >> x;
            cad[i] = x;
        }

        lista(2);
        cout << res << endl;
    }

    return 0;
}