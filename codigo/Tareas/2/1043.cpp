#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	float A,B,C,PERIMETRO,AREA;
	
	bool TRIANGULO;
	
	cin >> A >> B >> C;
	
	//Se determina si es posible hacer un triángulo
	
	if(A>B and A>C)
		if((B+C)>A)
			TRIANGULO=true;
		else 
			TRIANGULO=false;
	else if(B>C and B>A)
		if((A+C)>B)
			TRIANGULO=true;
		else 
			TRIANGULO=false;
	else 
		if((A+B)>C)
			TRIANGULO=true;
		else 
			TRIANGULO=false;
			

	//Si es posible se calcula su perímetro, si no lo es, se calcula el área de un trapecio
	
    if(TRIANGULO==true){
	    PERIMETRO=A+B+C;
		cout << fixed << setprecision(1) << "Perimetro = " << PERIMETRO <<endl;
	}else{
		AREA=(A+B)/2*C;
		cout << fixed << setprecision(1) << "Area = " << AREA <<endl;}
}
