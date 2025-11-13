#include <stdio.h>
#include <algorithm>

using namespace std; 

int SUMAS(int planks[], int height, int planks_to_complete, int &K) {

    int begin, end, vertical_planks, planks_used;
    begin = 0;
    end = K - 1;
    vertical_planks = 0;
    planks_used = 0;

    while (true) {

        if (vertical_planks == planks_to_complete) break;
        if (begin >= end) return -1;

        if (planks[end] > height) end--; 
        else if (planks[end] == height) {
            end--;
            vertical_planks++;
            planks_used++;
        }
         else {

            if (begin != end) {
                while (true) {
                    if (planks[begin] + planks[end] == height) {
                        begin++;
                        vertical_planks++;
                        planks_used += 2;
                        break;
                    }
                    if (planks[begin] + planks[end] > height)
                        break;

                    begin++;
                }
                end--;
            }
        }
    }

    return planks_used;
}

int main() { 
	
	int N, M, L, K, X, TABLAS_N = -1, TABLAS_M = -1; 
	
	for(;;){ 
		
		scanf("%d%d", &N, &M);
		
		if(N==0 and M==0)break; 
		
		scanf("%d%d", &L, &K); 
		

		int MADERAS[K];
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