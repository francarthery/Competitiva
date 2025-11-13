#include <iostream>

using namespace std; 

int SUMAS(int MADERAS[], int &LONG, int &ANCHO, int &L, int &K){ //LONG puede ser M o N dependiendo del llamado a la función

    float NECESITO = ANCHO/((float)L/100); //Cuantas maderas en ancho necesito para cubrir el suelo
    int TENGO = 0;
    int C_MADERAS = K;

    for (int i = 0; i < K; i++){ //Chequeo si hay tablas que sumadas=M/N

        for (int j = K-1; j > 0; j--){

            if(TENGO == NECESITO){
                return K-C_MADERAS;
                break;
            }
            else if (MADERAS[i] == LONG){ 
                TENGO++;
                MADERAS[i] = 0;
                C_MADERAS--;
            } 
            else if(MADERAS[j] == LONG){ 
                TENGO++;
                MADERAS[j] = 0;
                C_MADERAS--;
            }
            else if(MADERAS[i] + MADERAS[j] == LONG and j != i){
                TENGO++;
                MADERAS[i] = 0;
                MADERAS[j] = 0;
                C_MADERAS-=2;
            }
        }
    }
    
    return -1;
}

int main() { 

    int N, M, L, K, X; 

    for(;;){ 

        cin >> N >> M;

        if(N==0 and M==0)break; 

        cin >> L >> K; 

        int MADERAS[K];
        int MADERAS2[K]; 

        for(int i = 0; i < K; i++){ 
            cin >> X; 
            MADERAS[i]=X;
            MADERAS2[i]=X; 
        }

        if((M*100) % L != 0 and (N*100) % L != 0){ 
            cout << "impossivel" << endl; 
        }

        else{ 
            int TABLAS_N = SUMAS(MADERAS, N, M, L, K);
            int TABLAS_M = SUMAS(MADERAS2, M, N, L, K);

            if(TABLAS_N <= TABLAS_M and TABLAS_N != -1) 
                cout << TABLAS_N << endl; 

            else if(TABLAS_N > TABLAS_M and TABLAS_M != -1)
                cout << TABLAS_M << endl;

            else if(TABLAS_M == -1 and TABLAS_N != -1)
                cout << TABLAS_N << endl;

            else if(TABLAS_M != -1 and TABLAS_N == -1)
                cout << TABLAS_M << endl;

            else
                cout << "impossivel" << endl;
        }
    }

    return 0; 
} 