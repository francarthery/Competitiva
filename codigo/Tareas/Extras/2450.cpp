#include <iostream>
 
using namespace std;
 
int main() {
 
    int N, M;
    char R = 'S';
    bool FILA_ANT = false;

    cin >> N >> M;

    int MATRIZ[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> MATRIZ[i][j];
        }
    }
    
    for (int i = 0; i < N; i++){

        for (int j = 0; j < M; j++){
            
            if (MATRIZ[i][j] != 0){
                FILA_ANT = true;
                if (i < N - 1 and j < M - 1 and i > 0){
                    if (MATRIZ[i][j - 1] != 0 or MATRIZ[i + 1][j] != 0 or MATRIZ[i + 1][j - 1] != 0 or MATRIZ[i - 1][j] == 0){
                        R = 'N';
                        i = N; j = M;
                        break;
                    }
                    else
                        break;
                }   
            }
        }
    }

    cout << R << endl;
 
    return 0;
}

/*
Para que sea S:
    --Debe haber un N distinto a 0 en la fila superior
    --Todos los primeros N distintos a 0 de una fila deben tener 0 abajo a la izquierda y en diagonal
    --Todo 0 debe tener abajo un 0 si no se presento un N!=0 todavía

Sistema para verificar que haya un N != 0 en la fila anterior:
    --Crear variable bool FILA_ANT que guarde la fila anterior. Se inicializa en true.
    --Hago un contador de 0s. Si la cantidad de 0 llega a ser igual a M en una fila pasa a false la variable
    --Verificar que en una fila haya algun N diferente de 0, cambiar a true la variable si se da;
    --En la fila de abajo, si se presenta un N diferente de 0 ver si esa variable era True antes.
        -Si era True sigue siendo true.
        -Si era False hago break.



*/