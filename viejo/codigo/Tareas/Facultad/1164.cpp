#include <iostream>
 
using namespace std;

void perfecto(int X);
 
int main() {
 
    int N, X;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> X;
        perfecto(X);
    }
 
    return 0;
}

void perfecto(int X){
    int suma = 0;
    for(int i = 1; i < X; i++){
        if(X % i == 0) suma += i;
    }
    if(suma == X)
        cout << X << " eh perfeito" << endl;
    else
        cout << X << " nao eh perfeito" << endl;
}