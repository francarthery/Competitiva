#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int numeros[25];
	bool condicion1, condicion2;
	
	while(cin >> numeros[0]){
		
		condicion1 = false;
		condicion2 = true;
		
		for(int i = 1; i < 25; i++){
			
			if(i == 12){
				numeros[i] = 40;
			}
			else{
				cin >> numeros[i];
				if(numeros[i] <= (i % 5) * 15 or numeros[i] > (i % 5) * 15 + 15)
					condicion2 = false;
			}
		}
		
		sort(numeros, numeros + 25);
		
		if(numeros[0] > 0 and numeros[4] <= 15 and numeros[5] > 15 and numeros[9] <= 30 and numeros[10] > 30 and numeros[14] <= 45 and numeros[15] > 45 and numeros[19] <= 60 and numeros[20] > 60 and numeros[24] <= 75)
			condicion1 = true;
		
		if(condicion1 and condicion2)
			cout << "OK" << endl;
		else if(condicion1)
			cout << "RECICLAVEL" << endl;
		else
			cout << "DESCARTAVEL" << endl;
	}
	
	return 0;
}


/*
69 28 36 49 65 
13 22 45 59 72 
1 20 47 71 6 
19 43 56 75 5 
29 31 53 15

15 28 36 49 65
13 22 45 59 72
1 20 41 71 6 
19 43 56 75 5
29 31 53 69

69 65 72 71 75

[1, 15]  1 5 6 13 15 
[16, 30] 19 20 22 28 29
[31, 45] 31 36 43 45 
[46, 60] 47 49 53 56 59
[61, 75] 65 69 71 72 75

*/
