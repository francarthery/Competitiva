#include <iostream>
#include <array>
#include <cstdio>

using namespace std;
int main(){

    //Declaración variables
    float MITAD_N, CTRL_MAX, CTRL_MAX_C, VAL_MTRZ=1;
    int N;
    
    cin >> N;
    
    //Mientras el número introducido sea != de 0 va a ejecutar el resto de programa
    while(N!=0){
        
        MITAD_N=N/2.0;
        CTRL_MAX=1;
        int MATRIZ[N][N];

        //Va cambiando de fila en la matriz
        for (int c = 0; c<N; c++){
            VAL_MTRZ=c+1;
            CTRL_MAX_C=1;

            //Cambia de columna dentro de cada fila y asigna valores correspondientes
            for(int f=0; f<N; f++){
                
                //Condición para que VAL_MTRZ suba o baje
                if(c<=f)
                    VAL_MTRZ++;
                else
                    VAL_MTRZ--;
            
                MATRIZ[f][c]=VAL_MTRZ;

            if(c == 0)
                printf("%3d",MATRIZ[c][f]);
            else 
                printf(" %3d",MATRIZ[c][f]);
            
            }printf("\n");

            //Modifica la variable que controla el valor maximo y minimo de las filas

        }printf("\n");
                
        cin >> N;
    }

    return 0;
}