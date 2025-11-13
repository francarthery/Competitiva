#include <iostream>
 
using namespace std;

int promedio(int A, int B, int C);
 
int main() {
 
    int A, B, C;

    cin >> A >> B >> C;

    cout << "MEDIA = " << promedio(A, B, C) << endl;
 
    return 0;
}

int promedio(int A, int B, int C){

    int respuesta = (A*2 + B*3 + C*5) / 10;

    return respuesta;
}