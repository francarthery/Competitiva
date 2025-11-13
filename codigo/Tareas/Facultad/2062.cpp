#include <iostream>

using namespace std;
 
int main() {
 
    int N, i = 0;
    bool condicion;
    string texto;

    cin >> N;
    cin.ignore();
    getline(cin, texto);

    while(i < texto.length() - 1){

        condicion = (texto[i] == 'O' or texto[i] == 'U') and (texto[i + 1] == 'B' or texto[i + 1] == 'R');
        
        if(condicion and (i == 0 or texto[i - 1] == ' ') and ((i + 3 == texto.length()) or texto[i + 3] == ' ')){
            texto[i + 2] = 'I';
            i += 4;
        }
        else
            i++;
    }

    cout << texto << endl;
 
    return 0;
}