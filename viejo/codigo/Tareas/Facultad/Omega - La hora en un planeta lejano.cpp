#include <iostream>

using namespace std;

int main(){

    int segundos, dias, horas, minutos;

    cin >> segundos;

    //42000 sería la cantidad de segundos en un dia
    dias = segundos/42000;
    segundos -= dias*42000;

    horas = segundos/3500;
    segundos -= horas*3500;
    
    minutos = segundos/50;
    segundos -= minutos*50;

    cout << dias << " " << horas << " " << minutos << " " << segundos;

    return 0;
}