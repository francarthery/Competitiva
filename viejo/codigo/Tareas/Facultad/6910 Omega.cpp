#include <iostream>

using namespace std;

int main(){

    int n;
    
    cin >> n;

    if(0 <= n and n <= 6)
        cout << "Acido" << endl;
    else if(n == 7)
        cout << "Neutro" << endl;
    else if(n >= 8 and n <= 14)
        cout << "Base" << endl;
    else
        cout << "Are you kidding me?" << endl;

    return 0;
}