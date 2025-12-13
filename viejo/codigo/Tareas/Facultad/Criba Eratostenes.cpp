#include <iostream>
#include <cmath>

using namespace std;

void primos(int N);

int main(){

    int N;

    cin >> N;

    primos(N);

    return 0;
}


void primos(int N) {
    bool numeros[N + 1] = { false }; 

    for(int i = 2; i * i <= N; i++) {
        if(!numeros[i]) {
            for(int j = i * i; j <= N; j += i) {
                numeros[j] = true;
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        if(!numeros[i])
            cout << i << " ";
    }
}
