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
        for(int f=0; f<N; f++){
            VAL_MTRZ=1;
            CTRL_MAX_C=1;

            //Cambia de columna dentro de cada fila y asigna valores correspondientes
            for (int c = 0; c<N; c++){
                MATRIZ[f][c]=VAL_MTRZ;

                //Modifica el valor que va a ser introducido para que siga el patrón
                if(VAL_MTRZ<CTRL_MAX and c<(N/2))
                    VAL_MTRZ++;
                else if(VAL_MTRZ+1>CTRL_MAX_C and c+1>MITAD_N)
                    VAL_MTRZ--;
                
                //Modifica la variable que controla el valor maximo y mínimo de las columnas
                if(c+1<MITAD_N)
                    CTRL_MAX_C++;
                else if(c+1==MITAD_N)
            	    CTRL_MAX_C=CTRL_MAX_C;
                else
                    CTRL_MAX_C--;  

            if(c == 0)
                printf("%3d",MATRIZ[f][c]);
            else 
                printf("%4d",MATRIZ[f][c]);
            
            }printf("\n");

            //Modifica la variable que controla el valor maximo y minimo de las filas
            if(f+1<MITAD_N)
                CTRL_MAX++;
            else if(f+1==MITAD_N)
            	CTRL_MAX=CTRL_MAX;
            else
                CTRL_MAX--;

        }printf("\n");
                
        cin >> N;
    }

    return 0;
}

/*   

Cada vez que se realiza una fila VAL_MTRZ vuelve a 1

Hay que completar el array fila por fila
Tengo que hacer una variable que sea N-1 que controle el maximo que pueden alcanzar
los valores. Esto tambien va a depender de la columna



*/