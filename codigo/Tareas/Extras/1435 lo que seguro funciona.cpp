#include <iostream>
#include <array>
#include <cstdio>

using namespace std;
int main(){

    //Declaración variables

    int N;
    float VAL_MTRZ=1;

    cin >> N;
    
    while(N!=0){
        int MATRIZ[N][N];

        for(int f=0; f<N; f++){

            for (int c = 0; c<N; c++){
                
                
                if(c==0 or f==0 or f==N-1 or c==N-1)
                    VAL_MTRZ=1;
                else
                    VAL_MTRZ=2;

                MATRIZ[f][c]=VAL_MTRZ;

                 printf("%d   ", MATRIZ[f][c]);
                }       
           
            
           
            cout << "\n" << endl;
            }
        cin >> N;
    }

    return 0;
}