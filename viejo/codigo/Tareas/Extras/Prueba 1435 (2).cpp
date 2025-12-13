#include <stdio.h>
#include <algorithm>

using namespace std; 

int SUMAS(int MADERAS[], int &LONG, int NECESITO, int &K){ //LONG puede ser M o N dependiendo del llamado a la función
	
	int TENGO = 0;
	int C_MADERAS = K;
	
	for (int i = K-1; i >= 0; i--){ 
		
		if(TENGO == NECESITO){
				return K-C_MADERAS;
				break;
		}
		if(MADERAS[i] == LONG){ 
				TENGO++;
				MADERAS[i] = 0;
				C_MADERAS--;
				continue;
		}

		for (int j = 0; j < i; j++){  
			
			if(MADERAS[i] + MADERAS[j] > LONG)
				break;
		
			else if(TENGO == NECESITO){
				return K-C_MADERAS;
				break;
			}
			else if(MADERAS[i] + MADERAS[j] == LONG){
				TENGO++;
				MADERAS[i] = 0;
				MADERAS[j] = 0;
				C_MADERAS-=2;
				break;
			}
		}
	}
	
	if(TENGO < NECESITO)
	    return -1;
}

int main() { 
	
	int N, M, L, K, X, TABLAS_N = -1, TABLAS_M = -1; 
	
	for(;;){ 
		
		scanf("%d%d", &N, &M);
		
		if(N==0 and M==0)break; 
		
		scanf("%d%d", &L, &K); 
		
1		int MADERAS[K];
		int MADERAS2[K];
		TABLAS_M = -1; TABLAS_N = -1;
		
		for(int i = 0; i < K; i++){ 
			scanf("%d", &MADERAS[i]); 
		}

		sort(MADERAS, MADERAS+K);

		for(int i = 0; i < K; i++)
			MADERAS2[i] = MADERAS[i];

		
		if((N*100) % L == 0) 
			TABLAS_N = SUMAS(MADERAS, M, N*100 / L, K);
		
		if((M*100) % L == 0)
			TABLAS_M = SUMAS(MADERAS2, N, M*100 / L, K);
		
		if(TABLAS_M == -1 and TABLAS_N == -1)
			printf("impossivel\n");
		
		else

			if(TABLAS_N <= TABLAS_M and TABLAS_N != -1) 
				printf("%d\n",TABLAS_N); 
			
			else if(TABLAS_N > TABLAS_M and TABLAS_M != -1)
				printf("%d\n",TABLAS_M);
			
			else if(TABLAS_M == -1 and TABLAS_N != -1)
				printf("%d\n",TABLAS_N);
			
			else if(TABLAS_M != -1 and TABLAS_N == -1)
				printf("%d\n",TABLAS_M);
		
		}
	
	
	return 0; 
} 
