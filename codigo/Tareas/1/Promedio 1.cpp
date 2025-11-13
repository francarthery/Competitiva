#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	
	string N_EMPLEADO;
	double VENTAS_XMES,SALARIO,SALARIO_F;
	

	cin >> N_EMPLEADO >> SALARIO >> VENTAS_XMES;

	SALARIO_F=SALARIO+VENTAS_XMES*0.15;
	cout << fixed << setprecision(2);
	cout << "TOTAL = R$ " << SALARIO_F <<endl;
		
		
		return 0;
}
