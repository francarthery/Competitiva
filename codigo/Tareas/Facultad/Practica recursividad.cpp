#include <iostream>
 
using namespace std;

int cantdigitos(int n);
 
int main() {
 
    int N;

    cout << "introduce un número" << endl;

    cin >> N;

    cout << "La cantidad de dígitos es: " << cantdigitos(N) << endl;
 
    return 0;
}

int cantdigitos(int n){
    int rta = 1;

    if (n < 10)
        return rta;
    else{
        rta = 1 + cantdigitos(n / 10);
    }
}