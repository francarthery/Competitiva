#include <iostream>

using namespace std;

int main() {
	
	int A, C, X, laser=0;
    bool check_alt=false;

	for(;;){
		laser=0;
		cin >> A >> C;
		if(A==0 and C==0)break;
		
		int alt[C];
		
        //Carga alturas máximas lista
		for(int i=0; i<C; i++){
			cin >> X;
			alt[i]=X;
		}

        //Empieza en máxima altura y va bajando
		for(int i=A; i>0; i--){

            check_alt=false; //false: Había cuadrado antes;   True: No había cuadrado antes
			//Chequeo cuantas veces se llega a i altura
			for(int j=0; j<C; j++){
				if(alt[j]<i and check_alt==false){
                    laser++;
                    check_alt=true;
                    }
                else if(alt[j]>=i)
                    check_alt=false;

            }
		}
        cout << laser << endl;
	}
		
	
	return 0;
}


/*

Segunda hipótesis: Programa que funcione mirando las alturas más bajas y altas


Primer boceto:
--Creo una lista en la que guardo la altura de cada columna

--Creo una variable que se llame láser donde se guarda la cantidad de veces

--Contar cuantas columnas llegan a X valor empezando de mayor a menor. 
	--Verificar la posiciòn de esas columnas, si están últ o prim no va a ser
	lo mismo a que estén en el medio. Tambíen va a cambiar si las columnas
	están pegadas o separadas por espacio en blanco


Prueba:

5 8
1 2 3 2 0 3 4 5

RTA: 7
*/