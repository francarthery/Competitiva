#include <bits/stdc++.h>
using namespace std;

int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    string xpal, ypal;

    while(cin >> xpal >> ypal){
        auto inicio = chrono::high_resolution_clock::now(); //Obtener tiempo de inicio

        int acarreo, temp;
        vector<int> x, y, restot, restemp;
        
        for(int i = 0; i < xpal.length(); i++) x.push_back(xpal[i] - '0'); //Conversion string a vector int
        for(int i = 0; i < ypal.length(); i++) y.push_back(ypal[i] - '0');

        int tamres = x.size() + y.size();
        restot.resize(tamres);
        for(int i = y.size() - 1; i >= 0; i--){
            acarreo = 0;
            
            restemp.assign(tamres, 0); //Almacena resultado de digito multiplicador * multiplicando
            for(int j = x.size() - 1; j >= 0; j--){
                temp = x[j] * y[i] + acarreo;
                restemp[tamres + 1 - (x.size() - j) - (y.size() - i)] =  temp % 10;
                acarreo = temp / 10;
            }
            restemp[tamres - (x.size() + y.size() - i)] = acarreo;
            
            //Suma digito a digito al resultado total
            acarreo = 0;
            for(int j = tamres - 1; j >= 0; j--){
                temp = restemp[j] + restot[j] + acarreo;
                restot[j] = temp % 10;
                acarreo = temp / 10;
            }
        }

        if(restot[0]) cout << restot[0]; //Depende de si hay o no acarreo
        for(int i = 1; i < tamres; i++) cout << restot[i];
    
        cout << '\n';

        // Obtener el tiempo de fin
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio; // Calcular la duración
        cout << "El tiempo de ejecucion es: " << fixed << setprecision(10) << duracion.count() << " segundos" << '\n';
    }

    return 0;
}