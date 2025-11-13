#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, rta, cont;
    string nom, fir, aux;

    while(cin >> n and n != 0){
        cin.ignore();
        rta = 0;
        map<string, string> m;

        for(int i = 0; i < n; i++){
            cin >> nom >> fir;
            m[nom] = fir;
        }

        cin >> n;
        cin.ignore();

        for(int j = 0; j < n; j++){
            cont = 0;
            cin >> nom >> fir;
            aux = m[nom]; //Extraigo la firma original
            
            for(int i = 0; i < fir.length(); i++)
                if(fir[i] != aux[i]) cont++;

            if(cont > 1)
                rta++;
        }

        cout << rta << endl;
    }

    return 0;
}