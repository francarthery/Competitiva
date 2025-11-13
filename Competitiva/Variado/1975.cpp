#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, a, r, ma = 0;
    string aux, nombre;

    while(cin >> p >> a >> r and (p != 0 or a != 0 or r != 0)){
        cin.ignore();
        set<string> pe;
        map<string, vector<string>> m;
        vector<string> rta;
        ma = 0;

        for(int i = 0; i < p; i++){
            getline(cin, aux);
            pe.insert(aux);
        }

        for(int i = 0; i < a; i++){
            getline(cin, nombre);

            if(m.find(nombre) == m.end()){ //Si no se introdujo el nombre
                m[nombre] = vector<string>();
                for(int j = 0; j < r; j++){
                    getline(cin, aux);
                    if(pe.find(aux) != pe.end()){ // Si la respuesta es una perla la sumamos
                        m[nombre].push_back(aux);
                    }
                }
                ma = max(ma, int(m[nombre].size())); //Nos fijamos si cometio el maximo de errores
            }else{
                for(int j = 0; j < r; j++) getline(cin, aux); //Si ya salio pedimos el resto pero no lo usamos
            }
        }

        for(auto i : m){
            if(i.second.size() == ma){
                rta.push_back(i.first); //Por el tema de la coma lo paso a un vector para saber el numero final
            }
        }

        for(int i = 0; i < rta.size(); i++){
            cout << rta[i] << (i < rta.size() - 1 ? ", " : "");
        }
        cout << '\n';

    }


    return 0;
}