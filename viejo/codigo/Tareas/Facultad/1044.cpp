#include <iostream>
 
using namespace std;
 
int main() {
 
    int N, Mult, aux;

    cin >> N >> Mult;

    if (N > Mult){
        aux = N;
        N = Mult;
        Mult = aux;
    }

    if(Mult % N == 0){
        cout << "Sao Multiplos" << endl;
    }
    else{
        cout << "Nao sao Multiplos" << endl;
    }
 
    return 0;
}