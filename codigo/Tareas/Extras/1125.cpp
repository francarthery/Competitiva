/*
 Entrada:
 
 G=N de carreras P=Cantidad de pilotos
 Q*P=Resultados de cada carrera en orden de piloto 1 2 3 4...
 Q
 Q...
 S=Cantidad de sistemas de anotaciónes
 K=Cantidad de personas en recibir puntos. k k k k k: cantidad de puntos por persona
 
 Salida
 Cada ganador por sistema de puntuación
 
 */

#include <iostream>
 
using namespace std;
 
int main() {
 
    int G, P, Q, S, K, k, R, mayor, contador;
    
    for(;;){
        cin >> G >> P;
        if(G==0 and P==0)break;
        int RES[G][P];
       
        //Se cargan todos los resultados de las carreras
        for (int f=0; f<G; f++) {
            for (int c=0; c<P; c++) {
                cin >> Q;
                RES[f][c]=Q;
        }}
        
        cin >> S;
        //Se cargan todos los sistemas de medición
        for(int i=0; i<S; i++){
            mayor=0;
            int POINTS[P]={0};
            cin >> K;
           
            //Dependiendo de la cantidad de valores evaluados, se van a pedir esos valores
            for (int j=0; j<K; j++) {
                cin >> k;
                //Bucle para que el valor de k se sume a todas las carreras
                for (int p=0; p<G; p++){
                    //Debo buscar en cada carrera quien salio en j+1 posición y sumarle puntos
                    for(int c=0; c<P; c++){
                        if(RES[p][c]==j+1)
                            POINTS[c]+=k;
                }}}

            //Buscamos el/los valores mayores del array de puntos, ordenamos e imprimimos
            for(int j=0; j<P; j++){
                contador=0;
                if(POINTS[j]>mayor)
                    mayor=POINTS[j];
            }
                for(int p=0; p<P; p++){
                    if(POINTS[p]==mayor and contador==0){
                        cout << p+1;
                        contador+=1;
                    }
                    else if(POINTS[p]==mayor and contador!=0)
                        cout << " " << p+1;
                    }
            cout << endl;
        }}
 
    return 0;
}

/* 

Introduzco cantidad carreras y pilotos

Introduzco resultados por carrera cada corredor

Pido cantidad de sistemas de medición

Introduzco la cantidad de posiciónes puntuadas y los puntos por posición respectivamente

Me introduzco en un sistema
    sumo al array de puntuaciones la suma de cada valor k por cada j posición en las carreras

    Ordeno array con puntuaciónes

    Inprimo el/los ganadores

Paso al siguiente sistema

*/