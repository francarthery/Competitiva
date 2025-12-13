#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    int N, rta;
    
    cin >> N;
    string palabra;
    cin.ignore();
    
    for(int i = 0; i < N; i++){
        rta = 1;
        
        getline(cin, palabra);
        for(int j = 0; j < palabra.length(); j++){
            if(tolower(palabra[j]) == 'a' or tolower(palabra[j]) == 'e' or tolower(palabra[j]) == 'i' or tolower(palabra[j]) == 'o' or tolower(palabra[j]) == 's')
                rta *= 3;
            else
                rta *= 2;
        }
        cout << rta << endl;
    }
 
    return 0;
}