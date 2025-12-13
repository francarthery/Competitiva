#include <iostream>
 
using namespace std;
 
int main() {
 
    int H, D, Z, resultado;

    cin >> H >> D >> Z;

    resultado = H + D + Z;

    if(resultado >= 24)
        resultado -= 24;
    else if(resultado < 0){
        resultado += 24;
    }

    cout << resultado << endl;
 
    return 0;
}