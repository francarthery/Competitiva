#include <iostream>
 
using namespace std;
 
int main() {
 
    int Am, Rm, Em, Av, Rv, Ev, Matheus, Vinicius;
    string texto;

    cin >> Am >> Rm >> Em >> Av >> Rv >> Ev;
    cin.ignore();
    getline(cin, texto);

    Matheus = Am * 2 + Rm + Em * texto.length();
    Vinicius = Av * 2 + Rv + Ev * texto.length();

    if(Matheus < Vinicius)
        cout << "Matheus" << endl;
    else if(Matheus > Vinicius)
        cout << "Vinicius" << endl;
    else
        cout << "Empate" << endl;
 
    return 0;
}