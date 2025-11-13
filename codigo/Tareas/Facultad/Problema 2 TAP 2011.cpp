#include <iostream>

using namespace std;

int main(){

    long long int N, M, resultado = 0;
    int capitulos[100000];

    cin >> N >> M;
    
    while(N != -1 and M != -1){
        resultado = 0;
        for(int i = 0; i < N; i++){
            cin >> capitulos[i];
            resultado += (N - i) * capitulos[i] * M;
        }

        cout << resultado << endl;
        cin >> N >> M;
    }

    return 0;
}
