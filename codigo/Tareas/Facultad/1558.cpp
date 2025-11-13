#include <iostream>
 
using namespace std;

#define TAM 100
 
int main() {
 
    int N, n_max, i, j;
    int cuadrados[TAM];
    bool rta = false;

    for(int i = 0; i <= 100; i++){
        cuadrados[i] = i * i;
        n_max = i;
    }
    while(cin >> N){
        rta = false;
        i = n_max;
        j = 0;
        while(i >= j){
            if(cuadrados[i] + cuadrados[j] == N){
                rta = true;
                break;
            } 
            else if(cuadrados[i] + cuadrados[j] > N)
                i--;
            else
                j++;
        }
            
        if(rta)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
 
    return 0;
}
//1 4 9 16 25 36 49 64 81