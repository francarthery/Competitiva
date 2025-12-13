#include <iostream>

using namespace std;

const int MAX_M = 600;

int sig_fila(int &mayor, int &fila_inicio, int &columna_inicio, int &ultimo_fila, int &ultimo_columna, int &mayor_columna, int matriz[][MAX_M], int &N){
	
	//Se verifica si podemos continuar en la fila de abajo
	for(;;){
		if(matriz[ultimo_fila][mayor_columna] < matriz[ultimo_fila + 1][columna_inicio] and (ultimo_fila + 1) < N){
			ultimo_fila++;
			ultimo_columna = columna_inicio;
			
			while(matriz[ultimo_fila][ultimo_columna] < matriz[ultimo_fila][ultimo_columna+1] and ultimo_columna + 1 <= mayor_columna){
				ultimo_columna++;
			}
			
			mayor_columna = ultimo_columna;
			
			//Cálculo posible nuevo mayor
			if(mayor < ((ultimo_columna - columna_inicio) + 1) * ((ultimo_fila - fila_inicio) + 1)){
				mayor = ((ultimo_columna - columna_inicio) + 1) * ((ultimo_fila - fila_inicio) + 1);
			}
			//Si no quedan más valores consecutivos en la fila repetimos el proceso de bajar la fila
			sig_fila(mayor, fila_inicio, columna_inicio, ultimo_fila, ultimo_columna, mayor_columna, matriz, N);
			
		}
		//Si no se puede nos fijamos si el anterior de la fila si cumple la condición
		else{
			mayor_columna--;
		}
		//Esta condición implicaría que no existe un número que se pueda usar de la fila de abajo
		if(mayor_columna < columna_inicio){
			return mayor;
		}
	}
}
	
int main() {
    
    int N, M, mayor, fila_inicio, columna_inicio, ultimo_fila, ultimo_columna, mayor_global = 0, mayor_columna;
    
    for(;;){
        
        cin >> N >> M;
        
        if (N == 0 and M == 0)
            break;
        
        int matriz[600][600];
        mayor_global = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> matriz[i][j];
            }
        }
        
        //Probamos valor por valor de la matriz que submatrices podemos hacer
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                
                mayor = 1;
                fila_inicio = i;
                columna_inicio = j;
                ultimo_fila = i;
                ultimo_columna = j;
                
                //Se analiza cual es el máximo creciente por fila
                while(matriz[ultimo_fila][ultimo_columna] < matriz[ultimo_fila][ultimo_columna+1] and ultimo_columna + 2 <= M){
                    ultimo_columna++;
                }
                mayor_columna = ultimo_columna;
                
                if(mayor < ((ultimo_columna - columna_inicio) + 1) * ((ultimo_fila - fila_inicio) + 1)){
                    mayor = ((ultimo_columna - columna_inicio) + 1) * ((ultimo_fila - fila_inicio) + 1);
                }
                
                sig_fila(mayor, fila_inicio, columna_inicio, ultimo_fila, ultimo_columna, mayor_columna, matriz, N);
                
                if(mayor > mayor_global)
                    mayor_global = mayor;
            }
        }
        
        cout << mayor_global << endl;
        
    }
    
    return 0;
}
	

/*

Variables:

    --mayor: Almacena el mayor valor de la matriz que se puede construir iniciando en un valor específico.
    --mayor_global: Almacena la mayor submatriz que podemos construir en general.
    --fila_inicio: viene a ser lo mismo que i, guarda la fila donde empieza la matriz en el valor que nos encontramos.
    --columna_inicio: viene a ser lo mismo que j, guarda la columna donde empieza la matriz en el valor que nos encontramos.
    --ultimo_columna: ultima columna a la que puede llegar la submatriz.
    --ultimo_fila: ultima fila a la que puede llegar la submatriz.
    --mayor_columna: almacena la mayor columna a la que se llegó en la fila anterior y cuando bajamos de fila, si es necesario
    la vamos achicando para que se adecúe a lo que tenemos.
    




Recibimos matriz.

Empezando en matriz[0][0] nos fijamos si matriz[0][0] < matriz[0][1] 
    --Si lo es seguimos avanzando en la fila y guardando en una variable la longitud de valores crecientes en la fila.
    Se debe establecer una variable que vaya verificando cual es la secuencia creciente mayor

    --Si no lo es :
        **Guardamos el máximo valor creciente de la lista anterior
        **vamos a la fila de abajo y desde la columna del mayor valor de la fila anterior, vamos comparando si matriz[0][n] < matriz[1][0]
       
            --Si llegamos al primer valor de la lista significa que no podemos usar la fila de abajo

            --Si se cumple que: matriz[1][0] > matriz[0][n]]
                --Hay que mirar los valores si se cumple el crecimiento hacia la derecha
                Además, debemos constantemente ir guardando en MAYOR el tamaño que lleva nuestra matriz.

                --Si no se cumple el crecimiento debemos pasar a la fila de abajo y fijarnos si desde el último valor creciente de 
                la fila anterior hay crecimiento con respecto al primer valor de la fila de abajo.
                    --Si lo hay debemos continuar avanzando a la derecha y guardar en MAYOR el tamaño que lleva nuestra matriz.

                --Si no se cumple cortamos en la matriz en la última fila y columna donde se cumplió el crecimiento
            




*/