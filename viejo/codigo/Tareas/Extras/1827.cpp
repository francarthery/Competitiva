#include <cstdio>

using namespace std;
int main(){

    int N, VAL_MTRZ, MITAD_N;
    float TERCIO_N;
    bool CTRL_1=false;
    
    while(scanf("%d",&N)!=EOF){
        MITAD_N=N/2;
        TERCIO_N=N/3.00;
        int MATRIZ[N][N];

        for(int f=0; f<N; f++){
            
            for (int c = 0; c<N; c++){

                //Variación variable control 1
                if(c>=N/3 and f>=N/3 and f<TERCIO_N*2 and c<TERCIO_N*2)
                    CTRL_1=true;
                else if(c>=TERCIO_N*2 or f>=TERCIO_N*2)
                    CTRL_1=false;

                VAL_MTRZ=0;
                if(c==MITAD_N and f==MITAD_N)
                    VAL_MTRZ=4;
                else if(CTRL_1==true)
                    VAL_MTRZ=1;
                else if(c==f)
                    VAL_MTRZ=2;
                else if(c+f==N-1)
                    VAL_MTRZ=3;
            
                MATRIZ[f][c]=VAL_MTRZ;

            printf("%d",MATRIZ[f][c]);
            
            }printf("\n");
        }printf("\n");
    }

    return 0;
}

//Cuadrado de 1 comienza en N/3