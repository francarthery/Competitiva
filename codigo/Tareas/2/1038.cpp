#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	int CODIGO,C_PRODUCTO;
	float TOTAL;
	
	cin >> CODIGO >> C_PRODUCTO;
	
	if(CODIGO==1)
		TOTAL=4*C_PRODUCTO;
	else
		if(CODIGO==2)
		TOTAL=4.5*C_PRODUCTO;
		else
			if(CODIGO==3)
			TOTAL=5*C_PRODUCTO;
			else
				if(CODIGO==4)
				TOTAL=2*C_PRODUCTO;
				else
					if(CODIGO==5)
					TOTAL=1.5*C_PRODUCTO;
	
	
	cout << fixed << setprecision(2) << "Total: R$ " << TOTAL << endl;
	
	
	
	return 0;
}
