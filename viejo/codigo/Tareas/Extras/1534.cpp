#include <cstdio>

using namespace std;
int main(){

    int N, VAL_MTRZ;
    
    while(scanf("%d",&N)!=EOF){
        
        int MATRIZ[N][N];

        for(int f=0; f<N; f++){
            
            for (int c = 0; c<N; c++){
                VAL_MTRZ=3;
                if(c+f==N-1)
                    VAL_MTRZ=2;
                else if(c==f)
                    VAL_MTRZ=1;
            
                MATRIZ[f][c]=VAL_MTRZ;

            printf("%d",MATRIZ[f][c]);
            
            }printf("\n");
        }
    }

    return 0;
}