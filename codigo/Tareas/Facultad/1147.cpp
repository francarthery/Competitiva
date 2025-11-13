#include <iostream>
	
	using namespace std;
	
	int main() {
		
		char caballo_y, caballo_x;
		int cont_movimientos, cont_casos = 0;
		
		do{
			cin >> caballo_y;
			if(caballo_y != '0'){
				cin >> caballo_x;
				
				int tablero[8][8] = {{0}};
				cont_movimientos = 0;
				cont_casos++;
				
				//Convierto a int la posición en X e Y del caballo.
				int caba_y = (int)(caballo_y - '0') - 1;
				int caba_x = (int)(caballo_x - 'a');
				
				for(int i = 0; i < 8; i++){
					// Pido la posición de cada uno de los peones y pongo un 1 donde pueden comer en el tablero
					cin >> caballo_y >> caballo_x;
					
					int peon_y = (int)(caballo_y - '0') - 1;
					int peon_x = (int)(caballo_x - 'a');
					
					if(peon_x - 1 >= 0 and peon_y -1 >= 0)
						tablero[peon_x - 1][peon_y - 1] = 1;
					
					if(peon_x + 1 <= 7 and peon_y - 1 >= 0)
						tablero[peon_x + 1][peon_y - 1] = 1;
				}
				
				
				if (caba_x - 2 >= 0){
					if(caba_y + 1 <= 7 and tablero[caba_x - 2][caba_y + 1] != 1)
						cont_movimientos++;
					if(caba_y - 1 >= 0 and tablero[caba_x - 2][caba_y - 1] != 1)
						cont_movimientos++;
				}
				if (caba_x - 1 >= 0){
					if(caba_y + 2 <= 7 and tablero[caba_x - 1][caba_y + 2] != 1)
						cont_movimientos++;
					if(caba_y - 2 >= 0 and tablero[caba_x - 1][caba_y - 2] != 1)
						cont_movimientos++;
				}
				if (caba_x + 1 <= 7){
					if(caba_y + 2 <= 7 and tablero[caba_x + 1][caba_y + 2] != 1)
						cont_movimientos++;
					if(caba_y - 2 >= 0 and tablero[caba_x + 1][caba_y - 2] != 1)
						cont_movimientos++;
				}
				if (caba_x + 2 <= 7){
					if(caba_y + 1 <= 7 and tablero[caba_x + 2][caba_y + 1] != 1)
						cont_movimientos++;
					if(caba_y - 1 >= 0 and tablero[caba_x + 2][caba_y - 1] != 1)
						cont_movimientos++;
				}
				
				cout << "Caso de Teste #" << cont_casos << ": " << cont_movimientos << " movimento(s)." << endl;
			}
		}
		while(caballo_y != '0');
 	
		return 0;
	}

