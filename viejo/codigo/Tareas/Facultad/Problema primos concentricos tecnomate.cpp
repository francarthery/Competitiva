#include <iostream>

using namespace std;

void primos(bool numeros[]);

//funciona hasta N = 70, para mas hay que ampliar el limite del buscador de primos

int main(){

    int N, primo1, primo2, primo3, primo4, i = 2, contador = 0;
    bool numeros[50000] = {false};
    bool flag = true, p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    string direccion;

    primos(numeros);

    cin >> N;
    cin.ignore();
    getline(cin, direccion);

    while(flag){

        if(numeros[i] == false)
            contador++;

        if(!p1 and contador == (N * N) - 3){
            primo1 = i;
            p1 = true;
        }
        else if(!p2 and contador == (N * N) - 2){
            primo2 = i;
            p2 = true;
        }
        else if(!p3 and contador == (N * N) - 1){
            primo3 = i;
            p3 = true;
        }
        else if(!p4 and contador == (N * N)){
            primo4 = i;
            p4 = true;
            flag = false;
        }
        i++;
    }

    if(direccion == "Horario")
        cout << primo1 << " " << primo2 << endl << primo4 << " " << primo3;
    else
        cout << primo1 << " " << primo4 << endl << primo2 << " " << primo3;

    return 0;
}


void primos(bool numeros[]){
    

    for(int i = 2; i * i <= 100000; i++) {
        if(!numeros[i]) {
            for(int j = i * i; j <= 100000; j += i) {
                numeros[j] = true;
            }
        }
    }
}