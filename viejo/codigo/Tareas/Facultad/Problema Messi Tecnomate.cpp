#include <iostream>

using namespace std;

void ordenar(string mostrar[], int cantidades[], int cant_jugadores);

int main(){

    int N, cant_jugadores = 0, posicion;
    bool aparecio = false;

    cin >> N;

    string jugadores[N], mostrar[N];
    int cantidades[N] = {0};

    //Dejamos todas las palabras capitalizadas
    for(int i = 0; i < N; i++){
        cin >> jugadores[i];

        for(int j = 0; j < jugadores[i].length(); j++){
            if(j > 0 and jugadores[i][j] < 'a')
                jugadores[i][j] += 32;
            else if(j == 0 and jugadores[i][j] >= 'a')
                jugadores[i][j] -= 32;
        }
    }

    //Creamos arrays que vamos a mostrar
    for(int i = 0; i < N; i++){
        
        for(int j = 0; j < cant_jugadores; j++){
            if(jugadores[i] == mostrar[j]){
                aparecio = true;
                posicion = j;
            }
        }
        if(aparecio == true){
            cantidades[posicion]++;
            aparecio = false;
        }
        else{
            mostrar[cant_jugadores] = jugadores[i];
            cantidades[cant_jugadores] = 1;
            cant_jugadores++;
        }
    }

    ordenar(mostrar, cantidades, cant_jugadores);

    for(int i = 0; i < cant_jugadores; i++){
        if(cantidades[i] > 1)
            cout << mostrar[i] << " " << cantidades[i] << endl;
    }

    return 0;
}

void ordenar(string mostrar[], int cantidades[], int cant_jugadores){
    int aux = 0;
    string auxL;
    //Ordenamos numéricamente
    for(int i = 0; i < cant_jugadores; i++){
        for(int j = i + 1; j < cant_jugadores; j++){
            if(cantidades[i] < cantidades[j]){
                aux = cantidades[i];
                cantidades[i] = cantidades[j];
                cantidades[j] = aux;

                auxL = mostrar[i];
                mostrar[i] = mostrar[j];
                mostrar[j] = auxL;
            }
        }
    }
    //Ordenamos alfabéticamente
    for(int i = 0; i < cant_jugadores; i++){
        for(int j = i + 1; j < cant_jugadores; j++){
            if(cantidades[i] == cantidades[j]){
                if(mostrar[i].compare(mostrar[j])){
                    auxL = mostrar[i];
                    mostrar[i] = mostrar[j];
                    mostrar[j] = auxL;
                }
            }
        }
    }
}
