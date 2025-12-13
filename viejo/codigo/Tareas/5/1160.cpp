#include <iostream>
using namespace std;
int main()
{
	int i, PA, PB, j ,T;
	
	double G1, G2;
	
	cin >> T;
	
	for(i=1; i<=T; i++){
		j=0;
		cin >> PA >> PB >> G1 >> G2;
		
		while(PA<=PB){
			PA = PA + ((PA*G1) / 100);
			PB = PB + ((PB*G2) / 100);
			j++;
			if(j > 100){
				cout << "Mais de 1 seculo." << endl;
				break;
			}
		}
		if(j <= 100)
			cout << j << " anos." << endl;
	}
	return 0;
}
