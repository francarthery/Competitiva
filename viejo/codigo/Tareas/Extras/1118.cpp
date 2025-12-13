#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	float N, I, SUMA;
	int NC=1;
	
	/*Controla cuantas veces se repite el ingreso de notas. NC empieza siendo 1 
	porque es el valor con el que se va a hacer el promedio*/
	while(NC!=2){
		I=0;
		SUMA=0;
		//Si NC (Novo calculo) =1 calcula promedio
		if(NC==1){
			//Calculo promedio con dos notas. Si esta fuera de [0;10] no cuenta
			while(I<2){
				cin >> N;
				if(N>=0 and N<=10){
					SUMA+=N;
					I++;}
				else
				   cout << "nota invalida" << endl;}
			//Una vez sacado el promedio se pregunta si se quiere repetir calc.
			cout << "media = " << fixed << setprecision(2) << SUMA/2 << endl;
			cout << "novo calculo (1-sim 2-nao)" << endl;}
		else
			cout << "novo calculo (1-sim 2-nao)" << endl;
		cin >> NC;}
	
	return 0;
}

/* #include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {

float N, I, SUMA;
int NC=1;

while(NC!=2){
	I=0;SUMA=0;
	
	if(NC==1){
		while(I<2){
			cin >> N;
			if(N>=0 and N<=10){
				SUMA+=N;
				I++;}
			else
			   cout << "nota invalida" << endl;}
		cout << "media = " << fixed << setprecision(2) << SUMA/2 << endl;
		cout << "novo calculo (1-sim 2-nao)" << endl;}
	else
	   cout << "novo calculo (1-sim 2-nao)" << endl;
	cin >> NC;}

return 0;
}  */
