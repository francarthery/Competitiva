#include <iostream>
#include <string>
using namespace std;

/*Hay que hacer que en una variable se almacenen, a medida que introduzco 
pares de numeros, todos los numeros que se encuentran en el medio, tomando
los extremos, y además sumar estos conjuntos numericos. Si el usuario ingresa un
valor menor o igual a 0 el programa mostrará todos estos valores.

Flujo:

Ingreso un par de valores al bucle while, si son mayores a 0:
	Se ordenan de menor a MAYOR
	Se almacena en la variable LISTA todos los numeros entre el par
	Se suman estos valores
	Se agregan al String LISTA
Cuando el valor no sea mayor a 0:
	Se sale del bucle while y se muestra la variable LISTA
*/

int main(int argc, char *argv[]) {
	
	int M,N,MENOR,MAYOR,suma;
	
	//Valor que se va a mostrar
	string LISTA;
	
	cin >> M >> N;
	
	while(M>0 and N>0){
		//Se ordenan los valores
		if(M>N){
			MENOR=N;
			MAYOR=M;}
		else{
			MENOR=M;
			MAYOR=N;}
		suma=0;
		
		//Bucle for para obtener lista de valores entre ambos numeros
		//También se obtiene la suma entre ambos números
		//Se utiliza el comando "to_string()" para pasar el int a string
		for(int i=MENOR; i<=MAYOR; i++){
			suma=suma+i;
			LISTA=LISTA+to_string(i)+" ";}
		
		//Se agrega a la variable LISTA el resultado de la suma de los valores 
		LISTA=LISTA+"Sum="+to_string(suma)+"\n";
		cin >> M >> N;
	}
	//Para que no de presentation error se elimina el ultimo \n de la lista
	size_t tam= LISTA.length(); //obtenemos el tamaño del string
	LISTA.erase(tam-1); //Borramos el ultimo valor (Se toma \n como uno solo)
	cout << LISTA << endl;
	
	return 0;
}


