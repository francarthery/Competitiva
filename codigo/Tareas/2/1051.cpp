#include <iostream>

#include <iomanip>
using namespace std;

int main() {
	
	float SALARIO, IMPUESTOS;
	
	cin >> SALARIO;
	
	if(SALARIO>2000 and SALARIO<=3000)
		IMPUESTOS=(SALARIO-2000)*0.08;
	else
		if(SALARIO>3000 and SALARIO<=4500)
			IMPUESTOS=1000*0.08+(SALARIO-3000)*0.18;
		else
			IMPUESTOS=1000*0.08+1500*0.18+(SALARIO-4500)*0.28;


	if(SALARIO>2000){
		cout << fixed << setprecision(2);
		cout << "R$ " << IMPUESTOS <<endl;
	}else
		cout << "Isento" <<endl;
	
	return 0;
}
