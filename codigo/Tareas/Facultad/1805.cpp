#include <iostream>
 
using namespace std;
 
int main() {
 
    int A, B, resultado;
    
    cin >> A >> B;
    
    resultado = (A + B) * ((B - A) + 1);
    
    cout << resultado << endl;
 
    return 0;
}