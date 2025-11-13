#include <iostream>

using namespace std;

int main(){

    int precio, cuotas;
    char forma_pago;

    cout << "Ingrese el importe total" << endl;
    cin >> precio >> forma_pago;

    if(
        case 'd' or 'D':
            if (precio > 3000)
                precio *= 0.85;
            break;
        
        case 'b' or 'B':
            precio *= 0.7;
            break;

        case 'c' or 'C':
            cout << "Ingrese la cantidad de cuotas"
            cin >> cuotas;
            if (cuotas == 3)
                precio;



    }

    return 0;
}