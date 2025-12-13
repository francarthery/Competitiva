/*
recibir entero de 4 cifras
sustituir cada digito por ese digito+7%10
intercambiar 1 con 3 y 2 con 4
4  6  8  9
*/

#include <iostream>

using namespace std;

int main(){

    int N, dig_1, dig_2, dig_3, dig_4;

    cin >> N;

    dig_1 = N / 1000;
    dig_2 = (N / 100) % 10;
    dig_3 = (N / 10) % 10;
    dig_4 = N % 10;

    dig_1 = (dig_1 + 7) % 10;
    dig_2 = (dig_2 + 7) % 10;
    dig_3 = (dig_3 + 7) % 10;
    dig_4 = (dig_4 + 7) % 10;

    cout << "El número codificado es: " << (char)((char)dig_3 + '0') << (char)((char)dig_4 + '0') << (char)((char)dig_1 + '0') << (char)((char)dig_2 + '0') << endl;

    return 0;
}