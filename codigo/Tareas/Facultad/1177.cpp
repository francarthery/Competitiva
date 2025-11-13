#include <iostream>
 
using namespace std;

#define TAM 1000
 
int main() {
    
    int T;
    int N[TAM];

    cin >> T;

    for(int i = 0; i < 1000; i++){
        N[i] = i % T;
    }

    for(int i = 0; i < 1000; i++){
        cout << "N[" << i << "] = " << N[i] << endl;
    }

    return 0;
}