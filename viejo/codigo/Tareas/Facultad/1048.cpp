#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
 
    float salario, recargo;
    int porcentaje;

    cin >> salario;

    if(salario <= 400){
        recargo = salario * 0.15;
        porcentaje = 15;
    }
    else if(salario <= 800){
        recargo = salario * 0.12;
        porcentaje = 12;
    }
    else if(salario <= 1200){
        recargo = salario * 0.10;
        porcentaje = 10;
    }
    else if(salario <= 2000){
        recargo = salario * 0.07;
        porcentaje = 7;
    }
    else{
        recargo = salario * 0.04;
        porcentaje = 4;
    }

    cout << fixed << setprecision(2) << "Novo salario: " << salario + recargo << endl;
    cout << fixed << setprecision(2) << "Reajuste ganho: " << recargo << endl;
    cout << "Em percentual: " << porcentaje << " %" << endl;
    

 
    return 0;
}