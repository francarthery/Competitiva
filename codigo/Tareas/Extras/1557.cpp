#include <array>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
int main(){

    //Declaración variables
    int N, VAL_MTRZ=1, VAL_F, SIZE=0;

    //Mientras el número introducido sea != de 0 va a ejecutar el resto de programa
    while(scanf("%d",&N)){

        if(N==0)break;
        SIZE=pow(pow(2, (N-1)), 2);    //((2^N-1)^2);
        VAL_F=1;
        int MATRIZ[N][N];

        for (int f=0; f<N; f++){
            VAL_MTRZ=VAL_F;
            
            for(int c = 0; c<N; c++){
                
                MATRIZ[c][f]=VAL_MTRZ;
                VAL_MTRZ*=2;

            if(c==0)
                printf("%*u", to_string(SIZE).length(), MATRIZ[c][f]);
            else 
                printf(" %*u", to_string(SIZE).length(), MATRIZ[c][f]);
            
            }printf("\n");
            VAL_F*=2;

        }printf("\n");
    }

    return 0;
}